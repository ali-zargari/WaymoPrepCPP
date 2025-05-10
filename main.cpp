#include <iostream>
#include <unordered_map>
#include <set>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        //what we really want to find is a form of all(some) possible combos, where order matters.
        set<int> dp;
        vector<string> v;


        struct Frame
        {
            int start;
            int end;
            string comb;
        };

        stack<Frame> stk;
        stk.push({0, 0, ""});

        while (!stk.empty())
        {
            Frame node = stk.top();
            stk.pop();
            int strt = node.start;
            int end = node.end;
            string comb = node.comb;

            if (strt > end && comb.size() == s.size())
                continue;

            v.push_back(comb);

            if (strt == end )
                stk.push({strt, end+1, comb+s[strt]});
            else
                stk.push({strt+1, end, comb+s[strt]});
            
            
        }


        // Print vector v
        for (const auto& str : v)
        {
            cout << str << ", " << endl;
        }
        return v.size();
    }
};


// Main function provided by user - unchanged.
int main()
{
    Solution s;

    s.numDecodings("1023");

    return 0;
}
