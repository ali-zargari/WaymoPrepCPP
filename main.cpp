#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {


        if (grid.size() == 0)
        {
            return 0;
        }


        int area = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));


        auto dfs = [&](int x, int y)
        {
            int temp_area = 1;
            int dir[4][2] = {{1, 0},{-1, 0},{0, 1},{0, -1}};
            stack<pair<int, int>> stk;

            stk.emplace(x, y);

            visited[x][y] = true;

            while (!stk.empty())
            {

                pair <int, int> node = stk.top();
                stk.pop();

                for (int* d :dir)
                {
                    if ((node.first + d[0] < grid.size() && node.first + d[0] >= 0) &&
                        (node.second + d[1] < grid[0].size() && node.second + d[1] >= 0) &&
                        !visited[node.first + d[0]][node.second + d[1]] &&
                        grid[node.first + d[0]][node.second + d[1]] == 1)
                    {
                        stk.emplace(node.first + d[0], node.second + d[1]);
                        temp_area += 1;
                        visited[node.first + d[0]][node.second + d[1]] = true;
                    }
                }
            }

            area = max(area, temp_area);
        };


        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    dfs(i, j);
                }
            }
        }

        return area;
    }
};



// To execute C++, please define "int main()"
int main() {

    Solution s;


    // Test case 1: Basic 4x5 grid with 2 islands
    vector<vector<int>> grid1 = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}
    };
    cout << "Expected: 4, Actual: " << s.maxAreaOfIsland(grid1) << endl;

    // Test case 2: Grid with no land ('1')
    vector<vector<int>> grid2 = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    cout << "Expected: 0, Actual: " << s.maxAreaOfIsland(grid2) << endl;

    // Test case 3: Grid with all land ('1')
    vector<vector<int>> grid3 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    cout << "Expected: 9, Actual: " << s.maxAreaOfIsland(grid3) << endl;

    // Test case 4: Grid with one vertical island
    vector<vector<int>> grid4 = {
        {1, 0, 0},
        {1, 0, 0},
        {1, 0, 0}
    };
    cout << "Expected: 3, Actual: " << s.maxAreaOfIsland(grid4) << endl;

    // Test case 5: Grid with one horizontal island
    vector<vector<int>> grid5 = {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };
    cout << "Expected: 4, Actual: " << s.maxAreaOfIsland(grid5) << endl;

    // Test case 6: Empty grid (edge case)
    vector<vector<int>> grid6 = {};
    cout << "Expected: 0, Actual: " << s.maxAreaOfIsland(grid6) << endl;


    return 0;
}
