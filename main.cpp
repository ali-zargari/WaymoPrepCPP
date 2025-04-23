#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        // Check if s1 is longer than s2, impossible for s1 to be a permutation
        if (s1.length() > s2.length()) {
            return false;
        }

        // Create frequency map for s1
        unordered_map<char, int> freq;
        for (char c : s1) {
            freq[c]++;
        }
        // Store the target count (length of s1)
        int target_count = s1.length(); // Renamed 'count' to avoid ambiguity

        // Initialize sliding window pointers
        int l = 0;
        // r is the right boundary (inclusive), so it starts at s1.length() - 1
        int r = s1.length() - 1;

        // Slide the window across s2
        while (r < s2.size()) {
            int check = 0; // Counter for matched characters in the current window
            bool jumped = false; // Flag to indicate if the window was jumped forward

            // Create a copy of the frequency map for checking the current window
            unordered_map<char, int> freq_copy = freq;

            // Check characters within the current window [l, r]
            for (int i = l; i <= r; i++) {
                // If character s2[i] is not required by s1 (not in freq_copy)
                if (freq_copy.find(s2[i]) == freq_copy.end()) {
                    // Jump the left pointer past this invalid character
                    l = i + 1;
                    // Calculate the potential new right pointer
                    int new_r = l + s1.length() - 1;

                    // Check if the new right pointer goes out of bounds
                    if (new_r >= s2.size()) {
                        // Not enough characters left for a full window, impossible to find permutation
                        return false;
                    }

                    // Update the right pointer for the next iteration of the outer loop
                    r = new_r;
                    jumped = true; // Mark that we jumped the window
                    break; // Exit the inner loop for this window check
                }

                // If the character s2[i] is required, but we've seen too many of them
                if (freq_copy[s2[i]] == 0) {
                     break; // Exit inner loop - this window failed
                }

                // Decrement the count for the found character
                freq_copy[s2[i]]--;
                check++; // Increment the count of matched characters

                // If all characters from s1 are accounted for in this window
                if (check == target_count) {
                    return true; // Found a permutation!
                }
            } // End of inner for loop (window check)

            // If the window check completed without finding a permutation
            // AND we didn't jump the window due to an invalid character
            if (!jumped) {
                // Slide the window one step to the right
                l++;
                r++;
            }
            // If we *did* jump, 'l' and 'r' are already set for the next
            // iteration of the outer while loop.
        }

        // If the loop finishes without returning true, no permutation was found
        return false;
    }
};

// Main function provided by user - unchanged.
int main()
{
    Solution s;
    cout << boolalpha; // Print true/false instead of 1/0
    cout << s.checkInclusion("adc", "dcda") << endl; // Output: true
    cout << s.checkInclusion("ab", "eidbaooo") << endl; // Output: true
    cout << s.checkInclusion("ab", "eidboaoo") << endl; // Output: false
    cout << s.checkInclusion("a", "b") << endl; // Output: false
    cout << s.checkInclusion("hello", "ooolleoooleh") << endl; // Output: false


    return 0;
}
