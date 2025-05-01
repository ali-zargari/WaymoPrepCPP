#include <climits>
#include <cmath>
#include <iostream>


using namespace std;

class Solution
{
public:

    long long MOD = 1000000007;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD; // Make sure base is within modulo range initially
        while (exp > 0) {
            // If exponent is odd, multiply result with base
            if (exp % 2 == 1) {
                res = (res * base) % MOD;
            }
            // Square the base and halve the exponent (integer division)
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        // Calculate the number of even and odd positioned indices
        long long num_even_indices = (n + 1) / 2;
        long long num_odd_indices = n / 2;

        // Calculate 5^(num_even_indices) % MOD
        long long count_even = power(5, num_even_indices);

        // Calculate 4^(num_odd_indices) % MOD
        long long count_odd = power(4, num_odd_indices);

        // Multiply the results and take modulo
        long long total = (count_even * count_odd) % MOD;

        return (int)total; // Cast to int if the function signature requires it
    }
};

// hit(1) adds hit to timestamp 1
// hit(2) adds hit to timestamp 2
// hit(3) adds hit to timestamp 3
// 1-2-3 ... 304
// get hit(4) 3-300 = -297...1 2 3

// --- Main function with test cases (modified slightly for clarity) ---
int main()
{
    Solution solution;
long long test1 = 1;
    long long test2 = 2;
    long long test3 = 3;
    long long test4 = 4;
    long long test5 = 5;
    long long test6 = 6;
    long long test7 = 7;
    long long test8 = 8;
    long long test9 = 50;

    cout << "Test 1 (n=1): " << solution.power(2, 100000) << endl;
    cout << "Test 2 (n=2): " << solution.countGoodNumbers(test2) << endl;
    cout << "Test 3 (n=3): " << solution.countGoodNumbers(test3) << endl;
    cout << "Test 4 (n=4): " << solution.countGoodNumbers(test4) << endl;
    cout << "Test 5 (n=5): " << solution.countGoodNumbers(test5) << endl;
    cout << "Test 6 (n=6): " << solution.countGoodNumbers(test6) << endl;
    cout << "Test 7 (n=7): " << solution.countGoodNumbers(test7) << endl;
    cout << "Test 8 (n=8): " << solution.countGoodNumbers(test8) << endl;
    cout << "Test 9 (n=9): " << solution.countGoodNumbers(test9) << endl;

    return 0;
}
