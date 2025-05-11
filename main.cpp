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

    long long coinChange(vector<int>& coins, long long amount)
    {
        if (amount == 0) return 0;
        unordered_map<long long, int> best{{0, 0}};
        stack<pair<int, long long>> stk;
        stk.push({0, 0});
        int ans = INT_MAX;

        while (!stk.empty())
        {
            auto [steps,sum] = stk.top();
            stk.pop();

            for (auto c : coins)
            {
                long long nxt = sum + c;
                int s = steps + 1;

                if (s >= ans || nxt > amount) continue;

                if (nxt == amount)
                {
                    ans = min(ans, s);
                }
                else
                {
                    auto it = best.find(nxt);
                    if (it == best.end() || s < it->second)
                    {
                        best[nxt] = s;
                        stk.push({s, nxt});
                    }
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }


    int maxProduct(vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return -1;
        }

        struct Frame
        {
            int index;
            vector<int> state;
        };

        stack<Frame> stk;
        stk.push({0, {}});
    }

    bool wordBreak(string s, vector<string>& wordDict)
    {
        string temp = s;

        stack<int> stk;
        unordered_map<int, int> memo;
        stk.push(0);

        while (!stk.empty())
        {
            int current = stk.top();

            stk.pop();

            if (current == s.size())
            {
                return true;;
            }

            if (current > s.size())
            {
                memo[current] = -1;
                continue;
            }

            for (const string& str : wordDict)
            {
                if (current + str.size() <= s.size() &&
                    s.compare(current, str.size(), str) == 0 &&
                    memo[current + str.size()] != -1)
                {
                    stk.push(current + str.size());
                }
            }
        }

        return false;
    }
};

    // Main function provided by user - unchanged.
    int main()
    {
        Solution s;
        vector<string> v = {"car", "ca", "rs", "d"};

        cout << boolalpha << s.wordBreak("carsd", v);



        return 0;
    }
    //}
