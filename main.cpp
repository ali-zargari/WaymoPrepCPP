#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {


        int l = 0;
        int r = nums.size()-1;
        int mid = l + (r-l)/2;
        int min = nums[0];

        while (l <= r)
        {
            mid = l + (r-l)/2;

            if (nums[mid] == target)
            {
                return mid;
            }

            // if right side is sorted
            if (nums[l] > nums[mid])
            {
                if (target > nums[mid] && target <= nums[r])
                {
                    l = mid + 1;
                } else
                {
                    r = mid -1;
                }
            }
            // if left side is sorted
            else
            {
                if (target < nums[mid] && target >= nums[l])
                {
                    r = mid - 1;
                } else
                {
                    l = mid + 1;
                }
            }

        }

        return -1;
    }
};


// Main function provided by user - unchanged.
int main()
{
    Solution s;
    vector<int> his = {3,4,5,6,1,2};

    cout << s.search(his, 2) << endl;
    return 0;
}