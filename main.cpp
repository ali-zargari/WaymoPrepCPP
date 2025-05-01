#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_set>
#include <unordered_map>


using namespace std;

class Solution
{
public:
    bool validFilmino(vector<vector<int>>& filmino)
    {
        int rows = filmino.size(), cols = filmino[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int,int>> q, next_region;

        // seed first region
        q.emplace(0, 0);
        visited[0][0] = true;
        int numcount      = 1;
        int current_label = filmino[0][0];

        const vector<pair<int,int>> dir = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        while (!q.empty() || !next_region.empty())
        {
            if (q.empty())
            {
                // check the one we just finished
                if (numcount != current_label)
                    return false;

                // skip any duplicates in next_region
                while (!next_region.empty() &&
                       visited[next_region.front().first][next_region.front().second])
                {
                    next_region.pop();
                }
                if (next_region.empty())
                    break;

                // start the next region
                auto start = next_region.front();
                next_region.pop();
                current_label = filmino[start.first][start.second];
                numcount      = 1;
                q.push(start);
                visited[start.first][start.second] = true;
            }

            auto [r,c] = q.front();
            q.pop();

            for (auto &d : dir)
            {
                int nr = r + d.first, nc = c + d.second;
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                    continue;
                if (visited[nr][nc])
                    continue;

                if (filmino[nr][nc] == current_label)
                {
                    if (++numcount > current_label)
                        return false;
                    visited[nr][nc] = true;
                    q.emplace(nr, nc);
                }
                else
                {
                    // no longer mark visited here
                    next_region.emplace(nr, nc);
                }
            }
        }

        // final region check
        if (numcount != current_label)
            return false;

        return true;
    }
};



// --- Main function with test cases (modified slightly for clarity) ---
int main()
{
    Solution s;

    /*
    // Test Case 1: Valid 2x2 filmino
    vector<vector<int>> filmino1 = {
        {1, 1},
        {1, 1}
    };
    cout << "Test 1 (2x2 square): " << (s.validFilmino(filmino1) ? "Valid" : "Invalid") << endl;


    // Test Case 2: Valid L-shape
    vector<vector<int>> filmino2 = {
        {1, 0},
        {1, 1}
    };
    cout << "Test 2 (L-shape): " << (s.validFilmino(filmino2) ? "Valid" : "Invalid") << endl;

    // Test Case 3: Invalid - disconnected pieces
    vector<vector<int>> filmino3 = {
        {1, 0, 1},
        {0, 0, 0},
        {1, 0, 1}
    };
    cout << "Test 3 (disconnected): " << (s.validFilmino(filmino3) ? "Valid" : "Invalid") << endl;
    */
    /*
    // Test Case 4: Valid - zigzag shape
    vector<vector<int>> filmino4 = {
        {1, 1, 0},
        {0, 1, 1}
    };
    cout << "Test 4 (zigzag): " << (s.validFilmino(filmino4) ? "Valid" : "Invalid") << endl;

    // Test Case 5: Invalid - not 4 pieces
    vector<vector<int>> filmino5 = {
        {1, 1, 1},
        {0, 1, 0}
    };
    cout << "Test 5 (wrong size): " << (s.validFilmino(filmino5) ? "Valid" : "Invalid") << endl;
    */
    // Test Case 6: 5x5 grid
    vector<vector<int>> filmino6 = {
        {2, 3, 6, 6, 6},
        {2, 3, 5, 6, 6},
        {1, 3, 5, 6, 4},
        {3, 1, 5, 4, 4},
        {3, 3, 5, 5, 4}
    };
    cout << "Test 6 (5x5 grid): " << (s.validFilmino(filmino6) ? "Valid" : "Invalid") << endl;


    return 0;
}
