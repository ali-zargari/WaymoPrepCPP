#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:

    int rob(vector<int>& nums) {

        if (nums.size() == 1)
        {
            return nums[0];
        }

        if (nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }

        vector<int> dp (nums.size());
        int res;

        dp[0] = nums[0];
        dp[1]= max(dp[0], nums[1]);

        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
            res = dp[i];
        }


        return res;
    }

};


// Main function provided by user - unchanged.
int main()
{
    Solution s;

    vector<int> test1 = {1, 3, 1};
    cout << "Test 1: Expected: 3, Actual: " << s.rob(test1) << endl;

    vector<int> test2 = {2, 7, 9, 3, 1};
    cout << "Test 2: Expected: 12, Actual: " << s.rob(test2) << endl;

    vector<int> test3 = {2, 1, 1, 2};
    cout << "Test 3: Expected: 4, Actual: " << s.rob(test3) << endl;


    return 0;
}
