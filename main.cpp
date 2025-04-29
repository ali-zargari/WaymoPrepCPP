#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        if (grid.size() == 0)
        {
            return 0;
        }

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        int island_count = 0;

        auto dfs = [&grid, &visited](int x, int y)
        {
            visited[x][y] = true;
            int dir [4][2]  = {{1, 0},{-1, 0},{0, 1},{0, -1}};
            stack<pair<int, int>> stk;
            stk.emplace(x, y);

            while (!stk.empty())
            {

                pair<int, int> node = stk.top();
                stk.pop();

                for (auto d: dir)
                {
                    if ((node.first + d[0] >= 0 && node.first + d[0] < grid.size()) &&
                        (node.second + d[1] >= 0 && node.second + d[1] < grid[0].size())) {

                        if (!visited[node.first + d[0]][node.second + d[1]] &&
                            grid[node.first + d[0]][node.second + d[1]] == '1')
                        {
                            visited[node.first + d[0]][node.second + d[1]] = true;
                            stk.emplace(node.first + d[0], node.second + d[1]);
                        }
                    }
                }
            }
        };


        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                //cout << grid[i][j] << " " << boolalpha<< (grid[i][j] == 1 && !visited[i][j]) ;
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    dfs(i, j);
                    island_count++;
                }
            }
            //cout << endl;
        }

        return island_count;
    }
};


// To execute C++, please define "int main()"
int main() {

    Solution s;


    // Test case 1: Basic 4x5 grid with 2 islands
    vector<vector<char>> grid1 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout << "Number of islands in grid1: " << s.numIslands(grid1) << endl; // Expected: 3

    // Test case 2: Grid with no land ('1')
    vector<vector<char>> grid2 = {
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    cout << "Number of islands in grid2: " << s.numIslands(grid2) << endl; // Expected: 0

    // Test case 3: Grid with all land ('1')
    vector<vector<char>> grid3 = {
        {'1', '1', '1'},
        {'1', '1', '1'},
        {'1', '1', '1'}
    };
    cout << "Number of islands in grid3: " << s.numIslands(grid3) << endl; // Expected: 1

    // Test case 4: Grid with one vertical island
    vector<vector<char>> grid4 = {
        {'1', '0', '0'},
        {'1', '0', '0'},
        {'1', '0', '0'}
    };
    cout << "Number of islands in grid4: " << s.numIslands(grid4) << endl; // Expected: 1

    // Test case 5: Grid with one horizontal island
    vector<vector<char>> grid5 = {
        {'0', '0', '0', '0'},
        {'1', '1', '1', '1'},
        {'0', '0', '0', '0'}
    };
    cout << "Number of islands in grid5: " << s.numIslands(grid5) << endl; // Expected: 1

    // Test case 6: Empty grid (edge case)
    vector<vector<char>> grid6 = {};
    cout << "Number of islands in grid6: " << s.numIslands(grid6) << endl; // Expected: 0 (if handled)


    return 0;
}
