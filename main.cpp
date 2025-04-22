#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {


        int l = 0;
        int r = nums.size()-1;
        int mid = l + (r-l)/2;


        while (l < r)
        {
            mid = l + (r-l)/2;

            if (nums[mid] < nums[r])
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }

        }

        return nums[l];
    }
};


// Main function provided by user - unchanged.
int main()
{
    Solution s;
    vector<int> his = {4,5,6,-1,0,1,2};

    cout << s.findMin(his) << endl;
    return 0;
}