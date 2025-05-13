#include <iostream>
#include <queue>
#include <unordered_map>
#include <set>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        // unordered_map<int, int> dp;
        // dp[s.size()] = 1;
        return 0;
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
        int curMin = 1;
        int curMax = 1;
        int res = nums[0];

        for (int i = 0; i < nums.size(); i++)
        {
            int temp = curMax * nums[i];
            curMax = max(max(nums[i] * curMax, nums[i] * curMin), nums[i]);
            curMin = min(min(temp, nums[i] * curMin), nums[i]);

            res = max(res, curMax);
        }

        return res;
    }

    bool wordBreak(string s, vector<string>& wordDict)
    {
        stack<int> stk;
        unordered_map<int, int> memo;
        stk.push(0);

        while (!stk.empty())
        {
            int current = stk.top();
            stk.pop();

            if (memo.contains(current) && memo[current] == -1)
            {
                continue;
            }

            if (current == s.size())
            {
                return true;;
            }

            bool deadend = true;
            for (const string& str : wordDict)
            {
                if (current + str.size() <= s.size() &&
                    s.compare(current, str.size(), str) == 0 &&
                    (!memo.contains(current + str.size()) || memo[current + str.size()] != -1))
                {
                    deadend = false;
                    stk.push(current + str.size());
                }
            }

            if (deadend)
            {
                memo[current] = -1;
            }
        }

        return false;
    }

    vector<vector<int>> allSubsets(vector<int> nums)
    {
        struct Frame
        {
            int index;
            vector<int> combination;
        };

        int maxCount = 1;

        stack<Frame> stk;
        stk.push({0, {}});

        vector<vector<int>> res;


        while (!stk.empty())
        {
            Frame current = stk.top();
            int index = current.index;
            vector<int> comb = current.combination;
            stk.pop();

            if (index == nums.size())
            {
                res.push_back(comb);
                continue;
            }


            stk.push({index + 1, comb});
            comb.push_back(nums[index]);
            stk.push({index + 1, comb});
            maxCount++;
        }


        cout << maxCount << endl;

        return res;
    }

    int lengthOfLIS(vector<int>& nums)
    {
        int count = 0;
        int index = 0;
        //int res = -1;

        struct Frame
        {
            int index;
            vector<int> comb;
        };

        stack<Frame> stk;
        stk.push({0, {}});
        vector<vector<int>> res;

        unordered_map<int, int> memo;

        //size, comb
        priority_queue<pair<int, vector<int>>> pq;

        while (!stk.empty())
        {
            Frame curr = stk.top();
            stk.pop();
            int index = curr.index;
            vector<int> comb = curr.comb;

            if (index >= nums.size())
            {
                res.push_back(comb);
                pq.emplace(comb.size(), comb);
                continue;
            }

            stk.push({index + 1, comb});

            if (comb.empty() || nums[index] > comb.back())
            {
                comb.push_back(nums[index]);
                stk.push({index + 1, comb});
            }
        }

        for (const auto& sequence : res)
        {
            for (const auto& num : sequence)
            {
                cout << num << " ";
            }
            cout << endl;
        }


        return pq.top().first;
    }


    bool canPartition(vector<int>& nums)
    {
        int total = 0;


        for (int i : nums)
        {
            total += i;
        }

        cout << total << endl;
        if (total % 2 != 0)
        {
            return false;
        }

        total = total / 2;

        vector<vector<bool>> visited(nums.size() + 1, vector<bool>(total + 1, false));


        struct Frame
        {
            int index;
            int sum;
        };


        stack<Frame> stk;
        stk.push({0, 0});
        unordered_map<int, int> memo;

        while (!stk.empty())
        {
            Frame curr = stk.top();
            stk.pop();
            int index = curr.index;
            int sum = curr.sum;

            if (sum == total)
            {
                return true;
            }

            if (sum > total)
            {
                continue;
            }

            if (index >= nums.size())
            {
                continue;
            }

            if (visited[index][sum])
                continue;

            visited[index][sum] = true;

            stk.push({index + 1, sum + nums[index]});
            stk.push({index + 1, sum});
        }

        return false;
    }

    int uniquePaths(int m, int n)
    {
        int arr[m][n];
        int res = 0;

        for (int i = 0; i < m; i++)
        {
            arr[i][0] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            arr[0][i] = 1;
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
            }
        }

        return arr[m - 1][n - 1];
    }


    int longestCommonSubsequence(string text1, string text2)
    {
        //Approach:


        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        for (int i = 0; i < text1.size(); i++)
        {
            for (int j = 0; j < text2.size(); j++)
            {
                if (text1[i] == text2[j])
                {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                }
                else
                {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[text1.size()][text2.size()];
    }

    int dfs(int index, int sum, vector<int>& prices, bool buy, unordered_map<string, int> dp)
    {
        if (index >= prices.size())
        {
            return 0;
        }

        int newsum = 0;

        string key = to_string(index) + "-" + to_string(buy);

        if (dp.find(key) != dp.end())
        {
            return dp[key];
        }

        int cooldown = dfs(index + 1, sum, prices, buy, dp);

        if (buy)
        {
            newsum = dfs(index + 1, sum, prices, false, dp) - prices[index];
            dp[key] = max(cooldown, newsum);
        }
        else
        {
            newsum = dfs(index + 2, sum, prices, true, dp) + prices[index];
            dp[key] = max(cooldown, newsum);
        }
        return dp[key];
    };

    int maxProfit(vector<int>& prices)
    {
        unordered_map<string, int> dp;
        return dfs(0, 0, prices, true, dp);
    }

    int changeDFS(int index, int sum, int amount, vector<int> coins, vector<vector<int>>& res, vector<int> curr, vector<vector<int>>& mp)
    {
        if (index >= coins.size() || sum > amount)
        {
            return 0;
        }
        if (sum == amount)
        {
            res.push_back(curr);
            return 1;
        }

        if (mp[index][sum] != -1)
        {
            return mp[index][sum];
        }

        int total = 0;

        curr.push_back(coins[index]);

        if (sum + coins[index] <= amount)
        {
            total += changeDFS(index, sum + coins[index], amount, coins, res, curr, mp);
        }

        curr.pop_back();

        if (index+1 < coins.size())
        {
            total += changeDFS(index + 1, sum, amount, coins, res, curr, mp);
        }

        mp[index][sum] = total;

        return total;
    }

    int change(int amount, vector<int>& coins)
    {
        vector<vector<int>> res;
        vector<vector<int>> mp(coins.size()+1, vector<int>(amount+1, -1));

        if (amount == 0) return 1;
        if (coins.empty()) return 0;
        int total = changeDFS(0, 0, amount, coins, res, {}, mp);

        return total;
    }
};

// Main function provided by user - unchanged.
int main()
{
    Solution s;

    vector<int> coins1 = {102,89,76,63,50,37,24,11};
    vector<int> coins2 = {2};
    vector<int> coins3 = {10};

    cout << "Test Case 1: Amount=5000, Coins=[102,89,76,63,50,37,24,11] - Expected: 992951208, Got: " << s.change(5000, coins1) << endl;
    cout << "Test Case 2: Amount=3, Coins=[2] - Expected: 0, Got: " << s.change(3, coins2) << endl;
    cout << "Test Case 3: Amount=10, Coins=[10] - Expected: 1, Got: " << s.change(10, coins3) << endl;

    return 0;
}
