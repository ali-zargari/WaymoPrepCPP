#include <iostream>
#include <queue>
#include <vector>


using namespace std;



class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minheap;
    int k;

public:

    KthLargest(int k, vector<int>& nums) {

        this->k = k;
        for (int i = 0; i < nums.size(); i++)
        {
            minheap.push(nums[i]);
            if (minheap.size() > k)
            {
                minheap.pop();
            }
        }



    }

    int add(int val) {
        minheap.push(val);
        for (int i = 0; i < minheap.size(); i++)
        {
            if (minheap.size() > k)
            {
                minheap.pop();
            }
        }

        return minheap.top();
    }
};



// Main function provided by user - unchanged.
int main()
{
    // Test cases for KthLargest
    vector<int> nums = {4, 5, 8, 2};
    int k = 3;

    // Step 1: Initialize KthLargest with k and an initial array
    KthLargest kthLargest(k, nums);

    // Step 2: Test add() function and print kth largest element
    cout << kthLargest.add(3) << endl; // Expected output: 4
    cout << kthLargest.add(5) << endl; // Expected output: 5
    cout << kthLargest.add(10) << endl; // Expected output: 5
    cout << kthLargest.add(9) << endl; // Expected output: 8
    cout << kthLargest.add(4) << endl; // Expected output: 8

    return 0;
}
