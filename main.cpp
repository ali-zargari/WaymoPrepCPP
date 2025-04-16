#include <iostream>
#include <deque>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

class Solution
{

public:
    bool oldHasDuplicate(vector<int>& nums)
    {
        set<int> s;
        int len = nums.size();

        for (auto i : nums)
        {
            // cout << i << endl;
            s.insert(i);
        }

         return !((len == s.size()));
    }

    bool hasDuplicate(vector<int>& nums)
    {
        return unordered_set(nums.begin(), nums.end()).size() != nums.size();
    }
};


int main()
{
    Solution* s = new Solution();
    vector<int>* v= new vector<int>();
    v->push_back(2);
    v->push_back(2);
    v->push_back(3);

    cout << s->hasDuplicate(*v);

}