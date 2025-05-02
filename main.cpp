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
    vector<int> getTotal(int N, const vector<pair<int, int>>& tickets)
    {
        unordered_map<int, int> timeline;
        vector<int> res;

        //find the maximum end in tickets
        int max_expiration = 0;

        for (int i = 0; i < tickets.size(); i++)
        {
            max_expiration = max(max_expiration, tickets[i].second);
            cout << max_expiration << endl;

        }

        //fill timeline
        for (auto [start, end] : tickets)
        {
            timeline[start]++;
            timeline[end+1]--;
        }
        int counter = 0;

        for (int i = 0; i < max_expiration+1; i++)
        {
            //cout << "Here" << endl;

            counter += timeline[i];
            res.push_back(counter);
        }

        return res;

    }
};


// --- Main function with test cases (modified slightly for clarity) ---
int main()
{
    Solution s;

    // Test Case 3: Multiple cars with overlapping times
    vector<pair<int, int>> test3 = {{1, 3}, {2, 4}};
    vector<int> result3 = s.getTotal(5, test3);
    cout << "Test 1 (Multiple cars): ";
    for (int x : result3) cout << x << " ";
    cout << endl;

    return 0;
}
