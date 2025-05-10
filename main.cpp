#include <iostream>
#include <unordered_map>
#include <set>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        //what we really want to find is a form of all(some) possible combos, where order matters.
        unordered_map<int, int> dp;
        vector<string> v;


        struct Frame
        {
            int index; // The current character index in 's' we are considering
            string combination; // The combination (subsequence) built so far
        };

        stack<Frame> stk;
        stk.push({0, s});
        int count = 0;

        while (!stk.empty())
        {
            Frame currentFrame = stk.top();
            stk.pop();

            int currentIndex = currentFrame.index;
            string currentCombination = currentFrame.combination;

            // Base case: If we have processed all characters in the string 's'
            if (currentIndex == s.length())
            {
                count++;
                continue;
            }

            if (currentCombination[currentIndex] == '0')
            {
                continue;
            }

            stk.push({currentIndex + 1, currentCombination});

            if (currentIndex < s.size()-1)
            {
                if (s[currentIndex] == '1' ||
                    ((s[currentIndex] == '2') && s[currentIndex+1] < '7'))
                {
                    stk.push({currentIndex + 2, currentCombination});
                }
            }

        }

        return count;
    }
};


// Main function provided by user - unchanged.
int main()
{
    Solution s;

    cout << s.numDecodings("28");

    return 0;
}
