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

    int minCostClimbingStairs(vector<int>& cost)
    {
        int first = cost[0];
        int second = cost[1];
        int index = 2;
        

        while (index < cost.size())
        {
            int temp = second;
            second = min(first, second) + cost[index];
            first = temp;
            index++;
        }

        return min(first, second);
    }
};


// Main function provided by user - unchanged.
int main()
{
    Solution s;

    // Test cases for climbStairs
    cout << "Testing climbStairs function:\n";
    cout << "n = 2: " << s.climbStairs(2) << " (Expected: 2)\n";
    cout << "n = 3: " << s.climbStairs(3) << " (Expected: 3)\n";
    cout << "n = 4: " << s.climbStairs(4) << " (Expected: 5)\n";
    cout << "n = 5: " << s.climbStairs(5) << " (Expected: 8)\n";

    // Test cases for minCostClimbingStairs
    cout << "\nTesting minCostClimbingStairs function:\n";
    vector<int> cost1 = {10, 15, 20};
    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

    cout << "Cost = [10,15,20]: " << s.minCostClimbingStairs(cost1) << " (Expected: 15)\n";
    cout << "Cost = [1,100,1,1,1,100,1,1,100,1]: " << s.minCostClimbingStairs(cost2) << " (Expected: 6)\n";

    return 0;
}
