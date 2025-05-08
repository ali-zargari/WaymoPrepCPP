#include <algorithm>
#include <iostream>
#include <stack>
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

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());


        struct Frame {
            int idx;              // next index in candidates
            int sum;              // sum so far
            vector<int> comb;     // current combination
        };

        //holds index
        stack<Frame> stk;
        stk.push({0, 0, {}});

        vector<vector<int>> res;
        
        while (!stk.empty())
        {
            Frame curr = stk.top();
            stk.pop();
            int idx = curr.idx;
            int sum = curr.sum;
            auto comb = curr.comb;

            for (int i = idx; i < candidates.size(); i++)
            {
                int total = sum + candidates[i];

                if (total > target)
                {
                    break;
                }


                auto temp = comb;
                temp.push_back(candidates[i]);

                if (total == target)
                {
                    res.push_back(temp);
                } else
                {
                    stk.push({i, total, temp});
                }

            }
        }
        
        return res;
        
    }


    vector<vector<int>> combinationSum2(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());


        struct Frame {
            int idx;              // next index in candidates
            vector<int> comb;     // current combination
        };

        //holds index
        stack<Frame> stk;
        stk.push({0, {}});

        vector<vector<int>> res;

        while (!stk.empty())
        {
            Frame curr = stk.top();
            stk.pop();
            int idx = curr.idx;
            auto comb = curr.comb;

            for (int i = idx; i < nums.size(); i++)
            {
                if (i > idx && nums[i] == nums[i-1])
                {
                    continue;
                }

                vector<int> temp = comb;
                temp.push_back(nums[i]);

                stk.push({i+1, temp});
                res.push_back(temp);
            }
        }

        res.push_back({});

        return res;

    }


};


// Main function provided by user - unchanged.
int main()
{
    Solution s;

    // Test Case 1
vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4};
int target1 = 8;
vector<vector<int>> result1 = s.combinationSum2(nums1);
cout << "Test Case 1 Results:" << endl;
for (const auto& combo : result1) {
    cout << "[ ";
    for (int num : combo) cout << num << " ";
    cout << "]" << endl;
}

// Test Case 2
vector<int> nums2 = {2, 5, 2, 1, 2};
int target2 = 5;
vector<vector<int>> result2 = s.combinationSum2(nums2);
cout << "\nTest Case 2 Results:" << endl;
for (const auto& combo : result2) {
    cout << "[ ";
    for (int num : combo) cout << num << " ";
    cout << "]" << endl;
}

// Test Case 3
vector<int> nums3 = {1};
int target3 = 1;
vector<vector<int>> result3 = s.combinationSum2(nums3);
cout << "\nTest Case 3 Results:" << endl;
for (const auto& combo : result3) {
    cout << "[ ";
    for (int num : combo) cout << num << " ";
    cout << "]" << endl;
}

    return 0;
}
