#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int>& A = nums1;
        vector<int>& B = nums2;

        if (A.size() > B.size())
        {
            swap(A, B);
        }

        int a_length = A.size();
        int b_length = B.size();

        int l = 0;
        int r = a_length;

        while (l <= r)
        {
            int a_part = (l + r)/2;
            int b_part = (a_length + b_length + 1) / 2 - a_part;

            int a_left = (a_part == 0) ? INT_MIN : A[a_part-1];
            int a_right = (a_part == a_length) ? INT_MAX : A[a_part];
            int b_left = (b_part == 0) ? INT_MIN : B[b_part-1];
            int b_right = (b_part == b_length) ? INT_MAX : B[b_part];

            if (a_left <= b_right && b_left <= a_right)
            {
                if ((a_length + b_length) %2 == 0)
                {
                    return (max(a_left, b_left) + min(a_right, b_right)) / 2.0;
                }
                return max(a_left, b_left);

            } else if (a_left > b_right)
            {
                r = a_part - 1;
            } else
            {
                l = a_part + 1;
            }

        }

        return -1;
    }
};

// Main function provided by user - unchanged.
int main()
{
    Solution s;
    vector<int> his = {0, 2, 3, 6, 7};
    vector<int> his2 = {1, 2, 3, 3, 4, 5 };

    cout << s.findMedianSortedArrays(his, his2) << endl;
    return 0;
}