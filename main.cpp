#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int water = 0;

        int left_wall=height[0], right_wall=height[height.size()-1];

        while (left < right)
        {
            if (height[left] < height[right])
            {
                if (left_wall<height[left])
                {
                    left_wall = height[left];
                } else
                {
                    water += (left_wall-height[left]);
                }
                left++;
            } else
            {
                if (right_wall<height[right])
                {
                    right_wall = height[right];
                } else
                {
                    water += (right_wall-height[right]);
                }
                right--;
            }
        }

        return water;
    }
};


int main()
{

    Solution s;

    vector<int> top = {0,2,0,3,1,0,1,3,2,1};

    cout << s.trap(top) << endl;

    return 0;
}

