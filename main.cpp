#include <iostream>
#include <queue>
#include <unordered_map>
#include <set>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    int dfs(int i, string& s, unordered_map<int, int> dp)
    {
        if (dp.contains(i)) return dp[i];
        if (s[i] == '0') return 0;

        int res = dfs(i + 1, s, dp);
        if (i < s.size() - 1)
        {
            if (s[i] == '1' ||
                (s[i] == '2' && s[i + 1] < '7'))
            {
                res += dfs(i + 2, s, dp);
            }
        }

        dp[i] = res;
        return res;
    }

    int numDecodings(string s)
    {
        unordered_map<int, int> dp;
        dp[s.size()] = 1;
        return dfs(0, s, dp);
    }

    long long coinChange(vector<int>& coins, long long amount) {
        if (amount == 0) return 0;
        unordered_map<long long,int> best{{0,0}};
        stack<pair<int,long long>> stk;
        stk.push({0,0});
        int ans = INT_MAX;

        while (!stk.empty()) {
            auto [steps,sum] = stk.top();
            stk.pop();

            for (auto c : coins) {
                long long nxt = sum + c;
                int s = steps + 1;

                if (s >= ans || nxt > amount) continue;

                if (nxt == amount) {
                    ans = min(ans, s);

                } else {
                    auto it = best.find(nxt);
                    if (it == best.end() || s < it->second) {
                        best[nxt] = s;
                        stk.push({s, nxt});
                    }
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }




};


// Main function provided by user - unchanged.
int main()
{
    Solution s;

    vector<int> coins = {25, 10, 5, 2, 1, 50, 100, 20, 40, 60};
    cout << s.coinChange(coins, 200) << endl;

    return 0;
}
