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

    int lengthOfLIS(vector<int>& nums) {

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

            stk.push({index+1, comb});

            if (comb.empty() || nums[index] > comb.back())
            {
                comb.push_back(nums[index]);
                stk.push({index+1, comb});
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


    bool canPartition(vector<int>& nums) {

    }
    
};

// Main function provided by user - unchanged.
int main()
{
    Solution s;

    //vector<int> test1 = {9,1,4,2,3,3,7};
    //cout << "Test 1 (Expected 4): \n" << s.lengthOfLIS(test1) << endl;

    // vector<int> test2 = {0,3,1,3,2,3};
    // cout << "Test 2 (Expected 4): " << s.lengthOfLIS(test2) << endl;


    return 0;
}
