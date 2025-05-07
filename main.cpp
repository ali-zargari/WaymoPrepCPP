#include <iostream>
#include <queue>
#include <set>
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
    vector<int> canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, set<int>> classes;
        vector<int> indegrees(numCourses, 0);
        queue<int> q;
        int numVisited = 0;
        vector<int> res;

        for (auto p:prerequisites)
        {
            indegrees[p[0]]++;
            classes[p[1]].emplace(p[0]);

        }

        for (int i = 0; i < indegrees.size(); i++)
        {
            if (indegrees[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
            numVisited++;

            for (int i:classes[node])
            {
                indegrees[i]--;
                if (indegrees[i] == 0)
                {
                    q.push(i);
                }
            }

        }
        
        return res;
    }
};



// Main function provided by user - unchanged.
int main()
{
    Solution s;

// Test Case 1: No prerequisites
    vector<vector<int>> prerequisites1;
    vector<int> result1 = s.canFinish(2, prerequisites1);
    cout << "Test Case 1 (No prerequisites): ";
    for (int x : result1) cout << x << " ";
    cout << endl;

    // Test Case 2: Valid prerequisites
    vector<vector<int>> prerequisites2 = {{1, 0}};
    vector<int> result2 = s.canFinish(2, prerequisites2);
    cout << "Test Case 2 (Valid prerequisites): ";
    for (int x : result2) cout << x << " ";
    cout << endl;

    // Test Case 3: Circular dependency
    vector<vector<int>> prerequisites3 = {{1, 0}, {0, 1}};
    vector<int> result3 = s.canFinish(2, prerequisites3);
    cout << "Test Case 3 (Circular dependency): ";
    for (int x : result3) cout << x << " ";
    cout << endl;

    // Test Case 4: Multiple valid prerequisites (4 classes)
    vector<vector<int>> prerequisites4 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> result4 = s.canFinish(4, prerequisites4);
    cout << "Test Case 4 (4 classes, valid dependencies): ";
    for (int x : result4) cout << x << " ";
    cout << endl;

    // Test Case 5: Complex circular dependencies (5 classes)
    vector<vector<int>> prerequisites5 = {{1, 0}, {2, 1}, {3, 2}, {4, 3}, {0, 4}};
    vector<int> result5 = s.canFinish(5, prerequisites5);
    cout << "Test Case 5 (5 classes, circular dependencies): ";
    for (int x : result5) cout << x << " ";
    cout << endl;

    return 0;
}
