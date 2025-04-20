#include <iomanip>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>


using namespace std;

class Solution {
public:


    int search(vector<int>& nums, int target) {

        if (nums.size() > 0 && (nums[0] > target || target > nums[nums.size()-1]))
        {
            return -1;
        }

        return bin_search(nums, target, 0, nums.size()-1);

    }

    int bin_search(vector<int>& nums, int target, int l, int h) {

        //int offset = l + (h-l) / 2;
        int mid = l + (h-l) / 2;


        if (l > h)
        {
            return -1;
        }

        if (nums[mid] == target)
        {
            return mid;
        } else if (target < nums[mid])
        {
            return bin_search(nums, target, l, mid-1);
        } else
        {
            return bin_search(nums, target, mid+1, h);
        }

    }

};



int main()
{

    Solution s;

    vector<int> his = {-1,0,2,4,6,8};

    cout << s.search(his, 8) << endl;

    return 0;
}

