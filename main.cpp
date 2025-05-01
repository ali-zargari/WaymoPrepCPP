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
    vector<int> canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        unordered_map<int, vector<int>> classes;
        map<int, int> indegree;
        vector<int> order;

        for (int i = 0; i < prerequisites.size(); i++)
        {
            classes[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (!indegree.count(i))
            {
                indegree[i] = 0;
            }
        }

        queue<int> q;
        for (auto &[k, v] : indegree)
        {
            if (v == 0)
            {
                q.push(k);
                //order.push_back(k);
            }
        }


        int numcourses = 0;

        while (!q.empty())
        {
            int curr = q.front();
            numcourses++;
            q.pop();
            //indegree[curr]--;

            order.push_back(curr);


            for (auto c : classes[curr])
            {
                if (--indegree[c] == 0)
                {
                    q.push(c);
                }
            }
        }

        cout << boolalpha << (numcourses == numCourses) << endl;
        return (numcourses == numCourses) ? order : vector<int>();
    }
};


// --- Main function with test cases (modified slightly for clarity) ---
int main() {
    Solution s;
// Test case 1: Simple DAG without cycles
    vector<vector<int>> prereq1 = {{1, 0}, {2, 1}, {3, 2}};
    vector<int> result1 = s.canFinish(4, prereq1);
    cout << "Test case 1 (Simple Chain): ";
    if (result1.empty()) { cout << "Error - Should not detect cycle"; }
    else { for (int i : result1) cout << i << " "; }
    cout << "\n---\n" << endl;

    // Test case 2: Simple cycle that should fail
    vector<vector<int>> prereq2 = {{1, 0}, {2, 1}, {0, 2}};
    vector<int> result2 = s.canFinish(3, prereq2);
    cout << "Test case 2 (Simple Cycle): ";
    if (result2.empty()) { cout << "Correctly detected cycle"; }
    else { cout << "Failed - Should detect cycle"; }
    cout << "\n---\n" << endl;

    // Test case 3: Complex DAG without cycles
    vector<vector<int>> prereq3 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> result3 = s.canFinish(4, prereq3);
    cout << "Test case 3 (Complex DAG): ";
    if (result3.empty()) { cout << "Error - Should not detect cycle"; }
    else { for (int i : result3) cout << i << " "; }
    cout << "\n---\n" << endl;

    // Test case 4: Complex cycle
    vector<vector<int>> prereq4 = {{1, 0}, {2, 1}, {3, 2}, {1, 3}};
    vector<int> result4 = s.canFinish(4, prereq4);
    cout << "Test case 4 (Complex Cycle): ";
    if (result4.empty()) { cout << "Correctly detected cycle"; }
    else { cout << "Failed - Should detect cycle"; }
    cout << "\n---\n" << endl;

    // Test case 5: Disconnected components without cycles
    vector<vector<int>> prereq5 = {{1, 0}, {3, 2}};
    vector<int> result5 = s.canFinish(4, prereq5);
    cout << "Test case 5 (Disconnected): ";
    if (result5.empty()) { cout << "Error - Should not detect cycle"; }
    else { for (int i : result5) cout << i << " "; }
    cout << "\n---\n" << endl;
    return 0;
}
