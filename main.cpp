#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size()-1;
        int area = 0;

        while (l < r)
        {
            int temp = (r-l) * min(heights[l], heights[r]);
            if (area < temp)
            {
                area = temp;
            }

            if (heights[l] < heights[r])
            {
                l++;
            } else
            {
                r--;
            }
        }

        return area;
    }
};


int main()
{

    Solution s;

    vector<int> top = {1,7,2,5,4,7,3,6};

    cout << s.maxArea(top) << endl;

    return 0;
}

