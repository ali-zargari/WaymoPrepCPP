#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // go through list starting from beginning+1.
        // if current number-1 exists in the list, find it delete it. (or maybe add it to a set). Then move on to the next index.
        // as long as the next consecutive number exists, keep adding, save the length. When next isnt available, reset.

        unordered_set<int> s(nums.begin(), nums.end());
        unordered_set<int> ts;
        int len = 0;


        for (int i = 0; i < nums.size(); i++)
        {

            int temp = nums[i];
            if (s.count(temp+1))
            {
                continue;
            }
            ts.insert(temp);
            while (s.count(temp-1))
            {
                temp--;
                ts.insert(temp);
            }
            if (len < ts.size())
            {
                len = ts.size();
            }
            ts.clear();

        }

        return len;

    }
};


int main()
{

    Solution s;
    vector<int> nums = {0, 100, 4, 200, 1, 3, 2, 6, 7};

    cout << s.longestConsecutive(nums);


    return 0;
}

