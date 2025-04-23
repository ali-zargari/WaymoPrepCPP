#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // lets say we have a string 'xyzxyzc'.
        // We want to find the length of the longest substring with unique characters.
        // We can keep adding chars to a set. When we find a character that exists, keep track of the length of the set (using max function), and clear set.
        // We keep adding to the newly cleared set, until we hit the same thing again

        unordered_set<char> sequence;
        int len = 0;
        int left = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (sequence.find(s[i]) != sequence.end())
            {
                len = max(len, (int) sequence.size());
                while (sequence.find(s[i]) != sequence.end())
                {
                    sequence.erase(s[left]);
                    left++;
                }
            }

            sequence.insert(s[i]);

        }
        return max(len, (int) sequence.size());
    }
};


// Main function provided by user - unchanged.
int main()
{
    Solution s;
    //vector<int> his = {5, 1, 5, 6, 7, 1};

    //vector<int> his2 = {1, 2, 3, 3, 4, 5 };

    cout << s.lengthOfLongestSubstring("dvdf") << endl;
    return 0;
}