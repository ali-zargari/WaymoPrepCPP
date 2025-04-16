#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;


        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            if (mp.contains(diff) && mp[diff] != i)
            {
                return {i, mp[diff]};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};


int main() {
    vector<int> v = {1, 2, 3, 4, 5, 4, 7};
    Solution* s = new Solution();

    vector<int> res = s->twoSum(v, 11);

    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;

    delete s;
    return 0;
}
