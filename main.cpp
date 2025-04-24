#include <iostream>
// #include <queue> // Not used
#include <string>
#include <vector> // Not used
#include <unordered_map>
// #include <unordered_set> // Not used
#include <limits> // For numeric_limits

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty() || t.length() > s.length()) {
            return "";
        }

        unordered_map<char, int> chars_needed; // Target counts from t
        for (char c : t) {
            chars_needed[c]++;
        }

        unordered_map<char, int> chars_copy; // Remaining needed chars for current window attempt

        int l = 0; // Left pointer, scans for start
        int r = 0; // Right pointer, expands window
        int start_of_current_window = -1; // Track where the current valid window started
        bool move_right = false; // Flag to control expansion phase

        // Result tracking
        string min_res = "";
        int min_len = numeric_limits<int>::max();

        // Outer loop primarily driven by 'l' advancing or resets
        while (l < s.size()) {

            if (!move_right) {
                // Phase 1: Advance 'l' to find a potential window start
                start_of_current_window = l; // Record potential start before check

                if (chars_needed.contains(s[l])) { // Found a character that is needed
                    // Start a new window attempt
                    chars_copy = chars_needed; // Reset the needed counts

                    // Process the starting character s[l]
                    // (Safe access because we know chars_needed contains s[l])
                    chars_copy[s[l]]--;
                    if (chars_copy[s[l]] == 0) {
                        chars_copy.erase(s[l]);
                    }

                    // Check if t has only 1 character and we found it
                    if (chars_copy.empty()) {
                         if (1 < min_len) { // Length is 1
                             min_len = 1;
                             min_res = s.substr(l, 1);
                         }
                         // Continue searching from the next position
                         l++;
                         r = l; // Keep r aligned
                         // move_right remains false
                         continue; // Go to next iteration of outer loop
                    }

                    // Switch to expansion phase
                    move_right = true;
                    r = l + 1; // Start r right after l
                    // *** FIX: Do not increment l here, let the end of the block handle it only if needed ***

                } else {
                    // s[l] is not needed, advance l
                    l++;
                    r = l; // Keep r aligned
                    // move_right remains false
                }

            } else { // move_right is true: Expanding phase
                // *** FIX: Check if r is out of bounds ***
                if (r >= s.size()) {
                    // Reached end of s while expanding, this window attempt failed.
                    // No more windows possible starting at start_of_current_window or later.
                    break; // Exit the outer while loop
                }

                char char_r = s[r];

                // Process the character s[r] being added to the window
                // Only decrement count if it's a character we *still* need
                if (chars_copy.contains(char_r)) {
                    chars_copy[char_r]--;
                    if (chars_copy[char_r] == 0) {
                        chars_copy.erase(char_r);
                    }
                }
                // Removed the problematic 'l = r - 1;' line here

                // Check if we have found a complete window
                if (chars_copy.empty()) {
                    // Found a valid window s[start_of_current_window ... r]
                    int current_len = r - start_of_current_window + 1;
                    // *** FIX: Compare length correctly ***
                    if (min_res.empty() || current_len < min_len) {
                        min_len = current_len;
                        // *** FIX: Use substr based on start and length ***
                        min_res = s.substr(start_of_current_window, current_len);
                    }

                    // Resetting for next window search:
                    l = start_of_current_window + 1; // Start search after the beginning of the found window
                    r = l; // Reset r to align with new l
                    move_right = false; // Go back to phase 1 (advancing l)
                    // chars_copy will be reset when phase 1 finds a start

                } else {
                     // Window not complete yet, continue expanding
                     r++;
                }
            } // End of if (!move_right) / else
        } // End of outer while loop

        return min_res;
    }
};


// Main function provided by user - unchanged.
int main()
{
    Solution s;
    string s1 = "ADOBECODEBANC";
    string s2 = "ABC";
    cout << "'" << s.minWindow(s1, s2) << "'" << endl; // Expected: 'BANC'

    string s3 = "OUZODYXAZV";
    string t3 = "XYZ";
    cout << "'" << s.minWindow(s3, t3) << "'" << endl; // Expected: 'YXAZ'

    string s4 = "a";
    string t4 = "a";
    cout << "'" << s.minWindow(s4, t4) << "'" << endl; // Expected: 'a'

     string s5 = "a";
    string t5 = "aa";
    cout << "'" << s.minWindow(s5, t5) << "'" << endl; // Expected: ""

    string s6 = "aa";
    string t6 = "aa";
    cout << "'" << s.minWindow(s6, t6) << "'" << endl; // Expected: "aa"


    return 0;
}
