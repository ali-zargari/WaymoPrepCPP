#include <iomanip>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>


using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // we can go one bar at a time. if we keep finding bigger bars, keep adding.
        // once we get to a bar that is shorter, then we calculate the areas before that bar, and pop it out of the stack.

        int area = 0;
        stack<int> areas;

        for (int i = 0; i <= heights.size(); i++)
        {

            while (!areas.empty() && (i == heights.size() || heights[areas.top()] >= heights[i]))
            {
                int temp = areas.top();
                int height = heights[temp];
                areas.pop();

                int width = areas.empty() ? i : i - areas.top() - 1;
                area = max(area, width*height);
            }
            areas.push(i);
        }

        return area;

    }
};



int main()
{

    Solution s;

    vector<int> his = {7,1,7,2,2,4};

    cout << s.largestRectangleArea(his) << endl;

    return 0;
}

