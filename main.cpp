#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        //int res = 0;

        int first = 1;
        int second = 1;

        for (int i = 0; i < n; i++)
        {
            int temp = second;
            second = first + second;
            first = temp;
        }

        return first;
    }
};


// Main function provided by user - unchanged.
int main()
{
    Solution s;

    cout << s.climbStairs(5);

    return 0;
}
