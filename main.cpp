#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        //we can have a set of size k. initilized with nums[0] through nums[k].
        // every time the window moves, we delete the first one, and add a new one to the set. While doing this,
        // we keep track of a max value. to keep track of the max values, we can also use a heap. any time a max is popped,
        // the second biggest will be first on the stack.

        priority_queue<pair<int, int>> max;
        vector<int> res;

        if (k == 1)
        {
            return nums;
        }

        for (int i = 0; i < k; i++)
        {
            max.push(pair<int, int>(nums[i], i));
        }

        res.push_back(max.top().first);

        int l = 0;
        int r = k-1;
        while (r < nums.size())
        {

            l++;
            r++;

            if (r < nums.size())
            {
                max.push(pair<int, int>(nums[r], r));

                while (max.top().second < l) {
                    max.pop();
                }

                if (!max.empty())
                    res.push_back(max.top().first);
            }

        }

        return res;
    }
};



// Main function provided by user - unchanged.
int main()
{
    Solution s;
    vector<int> nums = {7, 2, 4};
    vector<int> results = s.maxSlidingWindow(nums, 2);

    //cout << s.maxSlidingWindow(nums, 3) << endl; // Output: true

    for (auto i : results)
    {
        cout << i << " ";
    }
    

    return 0;
}
