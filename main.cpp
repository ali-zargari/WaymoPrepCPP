#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>


using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int prod = 1;
        unordered_set<int> zeros = {};

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
                prod *= nums[i];
            else
                zeros.insert(i);
        }

        cout << zeros.size() << endl;

        vector<int>* result = new vector<int>();



        if (zeros.size() > 1){
            for (auto i: nums)
            {
                result->push_back(0);
            }
        }
        else if (zeros.size() == 1)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                //cout << zeros.count(i) << " ";

                if (zeros.count(i) != 1)
                {
                    result->push_back(0);
                    //cout << 0 << " ";
                }
                else
                {
                    result->push_back(prod);
                    //cout << prod << " ";
                }

                //cout << result->at(i) << " ";
            }
        } else
        {
            for (int i = 0; i < nums.size(); i++)
            {

                result->push_back(prod/nums[i]);

            }
        }

        return *result;

    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<int> res;

    res = s.productExceptSelf(nums);

    for (auto i: res)
    {
        cout << i << " ";
    }

}
