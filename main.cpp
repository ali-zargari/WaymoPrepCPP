#include <iostream>
#include <queue>
#include <vector>


using namespace std;



class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> max_heap;
        int res = 0;

        if (stones.size() == 1)
        {
            return stones[0];
        }

        if (stones.size() == 0)
        {
            return 0;
        }

        for (int s: stones)
        {
            max_heap.push(s);
        }


        // we can use a max heap. We save top in a variable. then pop. Then we have the second highest to compare with.


        while (max_heap.size() >= 2)
        {

            int first = max_heap.top();
            max_heap.pop();

            int second = max_heap.top();
            max_heap.pop();

            res = first - second;
            
            if (res != 0)
            {
                max_heap.push(res);
            }

            if (max_heap.size() == 1)
            {
                return max_heap.top();
            }
        }

        return res;
    }
};



// Main function provided by user - unchanged.
int main()
{
    // Test cases for KthLargest


    Solution solution;
    // Test case 1: General case with multiple stones
    vector<int> stones1 = {2, 7, 4, 1, 8, 1};
    // first = 8, second 7. {2, 4, 1, 1} -> {2, 4, 1, 1, 1}
    // first = 4, second 2. {1, 1, 1} -> {2, 1, 1, 1}
    // first = 2, second 1. { 1, 1 } -> {1, 1, 1}
    // first = 1, second 1. { 1 }
    cout << "Test case 1: Expected: 1, Actual: " << solution.lastStoneWeight(stones1) << endl;

    // Test case 2: Single stone
    vector<int> stones2 = {5};
    cout << "Test case 2: Expected: 5, Actual: " << solution.lastStoneWeight(stones2) << endl;

    // Test case 3: No stones
    vector<int> stones3 = {};
    cout << "Test case 3: Expected: 0, Actual: " << solution.lastStoneWeight(stones3) << endl;

    // Test case 4: Equal stones - all will cancel out
    vector<int> stones4 = {4, 4, 4, 4};
    cout << "Test case 4: Expected: 0, Actual: " << solution.lastStoneWeight(stones4) << endl;

    // Test case 5: Large stones that leave a residue
    vector<int> stones5 = {10, 4, 9, 2};
    cout << "Test case 5: Expected: 1, Actual: " << solution.lastStoneWeight(stones5) << endl;

    return 0;
}
