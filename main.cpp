#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int l = 0, r = 1;

        while (r < prices.size())
        {
            if (prices[r] > prices[l])
            {
                profit = max(profit, prices[r] - prices[l]);

            } else
            {
                l = r;
            }
            r++;
        }

        return profit;

    }
};

// Main function provided by user - unchanged.
int main()
{
    Solution s;
    vector<int> his = {5, 1, 5, 6, 7, 1};

    //vector<int> his2 = {1, 2, 3, 3, 4, 5 };

    cout << s.maxProfit(his) << endl;
    return 0;
}