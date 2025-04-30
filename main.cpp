#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>


using namespace std;

class Solution {
public:
  vector<pair<int, int>> shortestPath(vector<vector<int>> grid, pair<int, int> start, pair<int, int> target) {

    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    vector<pair<int, int>> result;


    auto bfs = [&](int y, int x){

      auto key = [&](int r,int c){
        return (static_cast<long long>(r) << 32) | unsigned(c);
      };

      // parent map: child_key -> parent (r,c)
      unordered_map<long long, pair<int,int>> parent;
      parent[key(y,x)] = {-1,-1};  // root has no parent

      vector<pair<int, int>> dir = {{1, 0},{-1, 0},{0, 1},{0, -1}};
      visited[y][x] = true;

      queue<pair<int, int>> q;
      q.push({y, x});


      while(!q.empty()){
        pair<int, int> node = q.front();
        q.pop();


        if(node.first == target.first && node.second == target.second){
          vector<pair<int,int>> path;
          for(auto cur = node; cur.first != -1; cur = parent[key(cur.first,cur.second)])
            path.push_back(cur);
          reverse(path.begin(), path.end());
          result = path;
          return;
        }

        for(pair d:dir){
          if(node.first + d.first < (int) visited.size() &&
             node.first + d.first >= 0){

            if(node.second + d.second <(int) visited[0].size() &&
               node.second + d.second >= 0){

              if(!visited[node.first+d.first][node.second+d.second] &&
                     grid[node.first+d.first][node.second+d.second] != 1){

                visited[node.first+d.first][node.second+d.second] = true;
                q.push({node.first+d.first, node.second+d.second});
                parent[key(node.first+d.first, node.second+d.second)] = node;

              }
            }
          }
        }
      }


    };


    for(int i = start.first; i < (int) grid.size(); i++){
      for(int j = start.second; j < (int) grid[i].size();j++){
        if(grid[i][j] != 1 && !visited[i][j])
          bfs(i, j);
      }
    }

    return result;
  }


};

int main(){

  Solution s;
  vector<vector<int>> grid = {{0, 1, 0, 1, 0},
                              {0, 1, 0, 0, 0},
                              {0, 1, 0, 1, 0},
                              {0, 0, 0, 1, 0},
                              {0, 0, 0, 0, 0}};

  for(auto p: s.shortestPath(grid, {0, 0}, {0, 2})){
    cout << p.first << "," << p.second << " ";
  }

  return 0;
}