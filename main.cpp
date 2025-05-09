#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        //'a b a b d b a'

        if (s.size() == 0)
        {
            return "";
        }
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        string res = "";
        int resLen = 0;
        int resIndex = -1;

        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (s[j] == s[i]) { // Outer characters match
                    if (i - j < 2) { // Length 1 (i==j) or Length 2 (i==j+1)
                        dp[i][j] = true;
                    } else { // Length 3 or more
                        dp[i][j] = dp[i-1][j+1]; // Check inner palindrome s[j+1...i-1]
                    }

                    if (dp[i][j] && (i - j + 1 > resLen)) {
                        resLen = i - j + 1;
                        resIndex = j;
                    }
                }
            }
        }

        return s.substr(resIndex, resLen);

    }


    int countSubstrings(string s) {
        //'a b a b d b a'
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int count = 0;

        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (s[j] == s[i])
                {
                    if (i - j < 2)
                    {
                        dp[j][i] = true;
                    } else
                    {
                        dp[j][i] = dp[j+1][i-1];
                    }

                    if (dp[j][i])
                    {
                        count++;
                    }
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

    // Test cases
    vector<pair<string, string>> testCases = {
        {"babad", "bab"},
        {"cbbd", "bb"},
        {"a", "a"},
        {"ac", "a"},
        {"abba", "abba"},
        {"aaaaa", "aaaaa"},
        {"", ""}
    };

    for (const auto& test : testCases)
    {
        string result = s.longestPalindrome(test.first);
        cout << "Input: \"" << test.first << "\"\n";
        cout << "Expected: \"" << test.second << "\"\n";
        cout << "Output: \"" << result << "\"\n";
        cout << "Result: " << (result == test.second ? "PASS" : "FAIL") << "\n\n";
    }

    vector<pair<string, int>> countTestCases = {
        {"abc", 3},
        {"aaa", 6},
        {"abba", 6},
        {"", 0}
    };

    cout << "\nTesting countSubstrings:\n";
    for (const auto& test : countTestCases)
    {
        int result = s.countSubstrings(test.first);
        cout << "Input: \"" << test.first << "\"\n";
        cout << "Expected: " << test.second << "\n";
        cout << "Output: " << result << "\n";
        cout << "Result: " << (result == test.second ? "PASS" : "FAIL") << "\n\n";
    }

    return 0;
}
