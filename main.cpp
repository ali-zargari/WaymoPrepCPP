#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numPart(int n, vector<vector<int>> dislikes) {


        vector<vector<int>> adj(n+1);
        for (auto &e : dislikes) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> color(n+1, 0);


        for (int i = 1; i <= n; i++)
        {
            if (color[i] != 0) continue;

            color[i] = 1;
            queue<int> q;
            q.push(i);

            while (!q.empty())
            {
                int curr = q.front();
                q.pop();

                for (int d :adj[curr])
                {
                    if (color[d] == 0)
                    {
                        q.push(d);
                        color[d] = -1 * color[curr];
                    } else if (color[d] == color[curr])
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};


// To execute C++, please define "int main()"
int main() {

    Solution s;

    // Test Case 1: Simple case with 4 nodes
    vector<vector<int>> dislikes1 = {{1, 2}, {1, 3}, {1, 4}, {2, 3}};
    cout << "Test Case 1 (Expected: true): " << (s.numPart(4, dislikes1) ? "true" : "false") << endl;


    return 0;
}
