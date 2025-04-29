#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <ctime>
#include <map>
#include <set>
#include <stack>
#include <unordered_set>

using namespace std;

class Grid {
private:
    vector<vector<int>> grid;
    int row;
    int col;
public:
    Grid(int m, int n): grid(m, vector<int>(n))
    {
        row = m;
        col = n;
        fillGrid(m, n);
    }


    Grid(const vector<vector<int>>& customGrid)
    {
        grid = customGrid;
        row = grid.size();
        col = grid[0].size();
    }

    void fillGrid(int m, int n)
    {
        srand(time(nullptr));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                grid[i][j] = rand() % 2;
            }
        }

    }

    void displayGrid()
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

    void displayNeighbors() const {
        int m = grid.size();
        int n = m ? grid[0].size() : 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << "Cell [" << i << "][" << j << "]:  ";
                bool first = true;

                // up
                if (i > 0) {
                    cout << "up= " << grid[i-1][j];
                    first = false;
                }
                // down
                if (i + 1 < m) {
                    if (!first) cout << ", ";
                    cout << "down= " << grid[i+1][j];
                    first = false;
                }
                // left
                if (j > 0) {
                    if (!first) cout << ", ";
                    cout << "left= " << grid[i][j-1];
                    first = false;
                }
                // right
                if (j + 1 < n) {
                    if (!first) cout << ", ";
                    cout << "right= " << grid[i][j+1];
                    first = false;
                }

                if (first) {
                    cout << "none";
                }
                cout << "\n";
            }
        }
    }

    void bfs(pair<int, int> start, pair<int, int> target)
    {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        pair<int, int> node = start;

        vector<pair<int, int>> dir = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        q.push(node);
        visited[start.first][start.second] = true;

        while (!q.empty())
        {
            auto current = q.front();
            q.pop();

            if (current.first == target.first &&
                current.second == target.second)
            {
                cout << "found" << endl;
                return;
            }

            for (pair<int, int> d: dir)
            {
                if (d.first + current.first < row && d.first + current.first >= 0)
                {
                    if (d.second + current.second < col && d.second + current.second >= 0)
                    {
                        if (!visited[d.first + current.first][d.second + current.second] && grid[d.first + current.first][d.second + current.second] != 0)
                        {
                            q.push({d.first + current.first, d.second + current.second});
                            visited[d.first + current.first][d.second + current.second] = true;
                        }
                    }
                }
            }
        }
    }

    void dfs(pair<int, int> start, pair<int, int> target)
    {
        stack<pair<int, int>> stk;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        pair<int, int> node = start;

        vector<pair<int, int>> dir = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        stk.push(node);
        visited[start.first][start.second] = true;

        while (!stk.empty())
        {
            auto current = stk.top();
            stk.pop();

            if (current.first == target.first &&
                current.second == target.second)
            {
                cout << "found" << endl;
                return;
            }

            for (pair<int, int> d: dir)
            {
                if (d.first + current.first < row && d.first + current.first >= 0)
                {
                    if (d.second + current.second < col && d.second + current.second >= 0)
                    {
                        if (!visited[d.first + current.first][d.second + current.second] && grid[d.first + current.first][d.second + current.second] != 0)
                        {
                            stk.push({d.first + current.first, d.second + current.second});
                            visited[d.first + current.first][d.second + current.second] = true;
                        }
                    }
                }
            }
        }
    }
};



// To execute C++, please define "int main()"
int main() {


    //A, A, A, B, C, B
    //Grid g = Grid(20, 20);
    //g.displayGrid();
    //g.displayNeighbors();


    //


    // Create a custom grid
    vector<vector<int>> customGrid = {
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 1},
        {1, 0, 1, 0}
    };


    // Initialize a new Grid instance with the custom grid
    Grid customGridInstance(customGrid);
    cout << "Custom Grid:" << endl;
    customGridInstance.displayGrid();


    customGridInstance.dfs({0, 0}, {3, 2});

    return 0;
}
