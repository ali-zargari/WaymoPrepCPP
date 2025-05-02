#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <unordered_set>
#include <unordered_map>


using namespace std;

class Solution
{
public:
    int count_bits(int num)
    {
        int total = 0;

        int temp = num;

        while (temp != 0)
        {
            temp &= (temp - 1);
            total++;
        }

        return total;
    }

    int zero_bits(int num)
    {
        return sizeof(decltype(num))*8 - count_bits(num);
    }
};


// --- Main function with test cases (modified slightly for clarity) ---
int main()
{
    Solution s;

    // Test case 1: Number with multiple 1 bits
    cout << "Test 1: Number 7 (111 in binary)" << endl;
    cout << "Expected 1 bits: 3, Got: " << s.count_bits(7) << endl;
    cout << "Expected 0 bits: 29, Got: " << s.zero_bits(7) << endl;

    // Test case 2: Number with single 1 bit
    cout << "Test 2: Number 8 (1000 in binary)" << endl;
    cout << "Expected 1 bits: 1, Got: " << s.count_bits(8) << endl;
    cout << "Expected 0 bits: 31, Got: " << s.zero_bits(8) << endl;

    // Test case 3: Zero
    cout << "Test 3: Number 0" << endl;
    cout << "Expected 1 bits: 0, Got: " << s.count_bits(0) << endl;
    cout << "Expected 0 bits: 32, Got: " << s.zero_bits(0) << endl;

    // Test case 4: Large number
    cout << "Test 4: Number 15 (1111 in binary)" << endl;
    cout << "Expected 1 bits: 4, Got: " << s.count_bits(15) << endl;
    cout << "Expected 0 bits: 28, Got: " << s.zero_bits(15) << endl;

    return 0;
}
