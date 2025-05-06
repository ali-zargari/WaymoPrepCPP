#include <iostream>
#include <queue>
#include <stack>
#include <stdint.h>
#include <string>
#include <vector>


using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)
    {
    }
};

class Solution
{
public:
    void islandsAndTreasure(vector<vector<int>>& grid)
    {
        if (grid.empty() || grid[0].empty()) return;

        int inf = 2147483647;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> q;


        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 0)
                {
                    q.emplace(i, j);
                    visited[i][j] = true;
                }
            }
        }

        int dist = 0;

        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty())
        {
            int n = q.size();
            dist++;

            for (int i = 0; i < n; i++)
            {
                pair<int, int> node = q.front();
                q.pop();

                for (auto d : dir)
                {
                    int nr = d[0] + node.first;
                    int nc = d[1] + node.second;

                    if ((nr >= 0 && nr < grid.size()) &&
                        (nc >= 0 && nc < grid[nr].size()))
                    {
                        if (grid[nr][nc] == inf &&
                            grid[nr][nc] != -1 &&
                            !visited[nr][nc])
                        {
                            grid[nr][nc] = dist;
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }

        // Print the grid
        for (const auto& row : grid)
        {
            for (const auto& cell : row)
            {
                cout << cell << " ";
            }
            cout << endl;
        }
    }
};


// Main function provided by user - unchanged.
int main()
{
    Solution s;

    // Example 1
    vector<vector<int>> grid1 = {
        {2147483647, -1, 0, 2147483647},
        {2147483647, 2147483647, 2147483647, -1},
        {2147483647, -1, 2147483647, -1},
        {0, -1, 2147483647, 2147483647}
    };
    cout << "Example 1 Input:" << endl;
    s.islandsAndTreasure(grid1);

    // Example 2
    vector<vector<int>> grid2 = {
        {0, -1},
        {2147483647, 2147483647}
    };
    cout << "\nExample 2 Input:" << endl;
    s.islandsAndTreasure(grid2);

    // Example 3: Multiple treasures
    vector<vector<int>> grid3 = {
        {0, 2147483647, 0},
        {2147483647, -1, 2147483647},
        {0, 2147483647, 2147483647}
    };
    cout << "\nExample 3 Input:" << endl;
    s.islandsAndTreasure(grid3);


    // Example 4: Single cell
    vector<vector<int>> grid4 = {{0}};
    cout << "\nExample 4 Input:" << endl;
    s.islandsAndTreasure(grid4);


    // Example 5: All walls
    vector<vector<int>> grid5 = {
        {0, 2147483647, 2147483647, -1, 2147483647},
        {2147483647, 2147483647, 2147483647, -1, 2147483647},
        {2147483647, 2147483647, 2147483647, -1, 2147483647}
    };
    cout << "\nExample 5 Input:" << endl;
    s.islandsAndTreasure(grid5);

    return 0;
}
