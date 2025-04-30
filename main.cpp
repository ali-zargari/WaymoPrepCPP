#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>


using namespace std;

class Solution
{
public:
    //
    //centroid approach
    vector<pair<int, int>> shortestPathCentroid(vector<vector<int>> grid)
    {
        vector<pair<int, int>> spots;


        auto bfs = [&](int row, int col, pair<int, int> target)
        {
            vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
            vector<vector<pair<int, int>>> parents(grid.size(), vector<pair<int, int>>(grid[0].size(), {-1, -1}));
            queue<pair<int, int>> q;
            int distance = INT_MAX;
            pair<int, int> closest;


            visited[row][col] = true;
            q.push({row, col});

            while (!q.empty())
            {
                pair<int, int> node = q.front();
                q.pop();

                if (distance > abs(target.first - node.first) + abs(target.second - node.second))
                {
                    distance = abs(target.first - node.first) + abs(target.second - node.second);
                    closest = node;
                }

                for (auto d : dir)
                {
                    int nr = d.first + node.first;
                    int nc = d.second + node.second;

                    if (nr < grid.size() && nr >= 0 &&
                        nc < grid[node.first].size() && nc >= 0)
                    {
                        if (!visited[nr][nc] && grid[nr][nc] != 1 && grid[nr][nc] != 2)
                        {
                            q.push({nr, nc});
                            visited[nr][nc] = true;
                            parents[nr][nc] = node;
                        }
                    }
                }
            }

            spots.emplace_back(closest);
        };

        int sum_x = 0;
        int sum_y = 0;
        int count = 0;
        vector<pair<int, int>> starts;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    sum_x += i;
                    sum_y += j;
                    count++;
                    starts.emplace_back(i, j);
                }
            }
        }

        for (auto start : starts)
        {
            bfs(start.first, start.second, {sum_x / count, sum_y / count});
        }

        return spots;
    }


    pair<int, int> shortestPath(vector<vector<int>> grid)
    {
        vector<pair<int, int>> starts;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    starts.emplace_back(i, j);
                }
            }
        }

        vector<vector<int>> dist_grid(grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<int>> reachable_count(grid.size(), vector<int>(grid[0].size(), 0));

        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (pair<int, int> start : starts)
        {
            queue<pair<pair<int, int>, int>> q;
            pair<int, int> node = {start.first, start.second};
            vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

            q.push({{start.first, start.second}, 0});
            visited[start.first][start.second] = true;
            //int count = 0;

            while (!q.empty())
            {
                pair<int, int> node = q.front().first;
                int distance = q.front().second;
                q.pop();

                for (pair<int, int> d : dir)
                {
                    int nr = d.first + node.first;
                    int nc = d.second + node.second;

                    if (nr < grid.size() && nr >= 0 &&
                        nc < grid[nr].size() && nc >= 0)
                    {
                        if (!visited[nr][nc] && grid[nr][nc] != 1 && grid[nr][nc] != 2)
                        {
                            visited[nr][nc] = true;
                            int next_dist = distance + 1;
                            q.push({{nr, nc}, next_dist});

                            dist_grid[nr][nc] += next_dist;
                            reachable_count[nr][nc]++;

                        }
                    }
                }
            }
        }

        long long min = -1; // Keep variable name 'min', use -1 to signify not found yet
        pair<int, int> res = {-1, -1}; // Keep variable name 'res'


        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {

                if (grid[i][j] == 0 && reachable_count[i][j] == starts.size()) {

                    if (min == -1 || dist_grid[i][j] < min) {
                        min = dist_grid[i][j]; // Update min with the new lowest distance sum
                        res = {i, j};          // Update res with the coordinates of the best spot
                    }
                }
            }
            // cout << endl; // REMOVED
        }

        cout << "Distance Grid:" << endl;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                cout << dist_grid[i][j] << "\t";
            }
            cout << endl;
        }

        cout << "\nReachable Count Grid:" << endl;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                cout << reachable_count[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;


        return res;
    }
};

int main()
{
    Solution s;
    // 1 is wall, 2 is equipment
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 2, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    auto result1 = s.shortestPath(grid);
    cout << "Test case 1 - Original grid result:" << endl;
    cout << "Expected: Point near center of equipment cluster" << endl;
    cout << "Actual:" << result1.first << ", " << result1.second << endl;

    vector<vector<int>> grid2 = {
        {1, 1, 1, 1, 1, 1, 1},
        {1, 2, 2, 2, 0, 2, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 2, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 2, 2, 2, 0, 2, 1},
        {1, 1, 1, 1, 1, 1, 1}
    };

    auto result2 = s.shortestPath(grid2);
    cout << "\nTest case 2 - Symmetric grid result:" << endl;
    cout << "Expected: Central point equidistant from all equipment" << endl;
    cout << "Actual:" << result2.first << ", " << result2.second << endl;


    return 0;
}
