#include <iostream>
#include <queue>
#include <unordered_map>
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

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {


        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto row:flights)
        {
            adj[row[0]].emplace_back(row[2], row[1]);
        }


        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, src, 0);


        while (!pq.empty())
        {
            auto [cost, flt_num, steps] = pq.top();
            pq.pop();

            if (dst == flt_num) return cost;


            if (steps > k )
            {
                continue;
            }


            for (auto node:adj[flt_num])
            {
                pq.emplace(cost + node.first, node.second, steps+1);
            }
        }


        return -1;
    }
};


// Main function provided by user - unchanged.
int main()
{
    Solution s;

// Test Case 1: Simple path with direct flight
    // n = 3 cities (0,1,2), flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
    vector<vector<int>> flights1 = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int result1 = s.findCheapestPrice(3, flights1, 0, 2, 1);
    cout << "Test 1 Result: Expected = 200, Actual = " << result1
        << (result1 == 200 ? " (PASS)" : " (FAIL)") << endl;

    // Test Case 2: No path available
    // n = 3 cities, flights = [[0,1,100]], src = 0, dst = 2, k = 0
    vector<vector<int>> flights2 = {{0, 1, 100}};
    int result2 = s.findCheapestPrice(3, flights2, 0, 2, 0);
    cout << "Test 2 Result: Expected = -1, Actual = " << result2
        << (result2 == -1 ? " (PASS)" : " (FAIL)") << endl;

    // Test Case 3: Complex path with multiple options
    // n = 4 cities, multiple paths with different costs
    vector<vector<int>> flights3 = {{0, 1, 100}, {1, 2, 100}, {2, 3, 100}, {0, 3, 500}};
    int result3 = s.findCheapestPrice(4, flights3, 0, 3, 2);
    cout << "Test 3 Result: Expected = 300, Actual = " << result3
        << (result3 == 300 ? " (PASS)" : " (FAIL)") << endl;
    return 0;
}
