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

    vector<int> getToal(int N, vector<pair<int, int>> tickets)
    {
        // N timestamps: 0,1,…,N-1
        vector<int> diff(N + 1, 0);

        for (auto& t : tickets)
        {
            diff[t.first]++; // car arrives at time=in
            if (t.second + 1 <= N) // remove it after time=out
                diff[t.second + 1]--;
        }

        // build the prefix-sum to get counts at times 0..N-1
        vector<int> ans(N);
        int cur = 0;
        for (int time = 0; time < N; ++time)
        {
            cur += diff[time];
            ans[time] = cur;
        }
        return ans;
    }
};


// --- Main function with test cases (modified slightly for clarity) ---
int main()
{
    Solution s;

    // Test Case 3: Multiple cars with overlapping times
    vector<pair<int, int>> test3 = {{1, 3}, {2, 4}};
    vector<int> result3 = s.getToal(5, test3);
    cout << "Test 1 (Multiple cars): ";
    for (int x : result3) cout << x << " ";
    cout << endl;

    return 0;
}
