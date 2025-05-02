#include <vector>
#include <algorithm>
#include <map>
#include <iostream>


using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};

        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)
        {
            return a[0] < b[0];
        });

        //{1, 8}, {4, 5}
        //
        cout << "Sorted intervals: ";
        for (const auto& interval : intervals)
        {
            cout << "[" << interval[0] << "," << interval[1] << "] ";
        }
        cout << endl;


        for (int i = 1; i < (int) intervals.size(); i++) {

            if (intervals[i-1][1] >= intervals[i][0]) {

                intervals[i-1][1] = max(intervals[i][1], intervals[i-1][1]);
                intervals.erase(intervals.begin() + i);
                i--;
            }
        }

        return intervals;
    }
};

// --- Main function with test cases (modified slightly for clarity) ---
int main()
{
    Solution s;
    /*// Test case 1: Basic interval merging
    vector<vector<int>> test1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result1 = s.merge(test1);
    cout << "Test 1:\nExpected: [1,6] [8,10] [15,18]\nActual: ";
    for (const auto& p : result1)
    {
        cout << "[" << p[0] << "," << p[1] << "] ";
    }
    cout << endl;*/

    // Test case 2: Overlapping intervals
    vector<vector<int>> test2 = {{1, 8}, {4, 5}};
    vector<vector<int>> result2 = s.merge(test2);
    cout << "Test 2:\nExpected: [1,8]\nActual: ";
    for (const auto& p : result2)
    {
        cout << "[" << p[0] << "," << p[1] << "] ";
    }
    cout << endl;

    /*
    // Test case 3: Empty input
    vector<vector<int>> test3;
    vector<vector<int>> result3 = s.merge(test3);
    cout << "Test 3:\nExpected: Empty\nActual: ";
    if (result3.empty())
    {
        return 0;
    }
    */

    return 0;
}
