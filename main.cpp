#include <iostream>
// #include <queue> // Not used
#include <string>
#include <vector> // Not used
#include <unordered_map>
// #include <unordered_set> // Not used
#include <limits> // For numeric_limits

using namespace std;

class Solution
{
public:
    struct TreeNode
    {
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode() : val(0), left(nullptr), right(nullptr)
        {
        }

        TreeNode(int x) : val(x), left(nullptr), right(nullptr)
        {
        }

        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)
        {
        }
    };

    TreeNode* invertTree(TreeNode* root) //DFS
    {

        if (!root)
        {
            return nullptr;
        }

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};


// Main function provided by user - unchanged.
int main()
{
    Solution s;


    // Test Case 1: Empty tree
    Solution::TreeNode* root1 = nullptr;
    Solution::TreeNode* result1 = s.invertTree(root1);
    cout << "Test Case 1: " << (result1 == nullptr ? "Passed" : "Failed") << endl;

    // Test Case 2: Single-node tree
    Solution::TreeNode* root2 = new Solution::TreeNode(1);
    Solution::TreeNode* result2 = s.invertTree(root2);
    cout << "Test Case 2: " << (result2->val == 1 && result2->left == nullptr && result2->right == nullptr
                                    ? "Passed"
                                    : "Failed") << endl;

    // Test Case 3: Simple binary tree
    Solution::TreeNode* root3 =
        new Solution::TreeNode(1,
                               new Solution::TreeNode(2),
                               new Solution::TreeNode(3));
    Solution::TreeNode* result3 = s.invertTree(root3);
    cout << "Test Case 3: " << (result3->val == 1 && result3->left->val == 3 && result3->right->val == 2
                                    ? "Passed"
                                    : "Failed") << endl;

    // Test Case 4: Larger binary tree
    Solution::TreeNode* root4;
    root4 = new Solution::TreeNode(4,
                                   new Solution::TreeNode(2,
                                                          new Solution::TreeNode(1),
                                                          new Solution::TreeNode(3)),
                                   new Solution::TreeNode(7,
                                                          new Solution::TreeNode(6),
                                                          new Solution::TreeNode(9)));
    Solution::TreeNode* result4 = s.invertTree(root4);
    cout << "Test Case 4: "
        << (result4->val == 4 &&
            result4->left->val == 7 && result4->right->val == 2 &&
            result4->left->left->val == 9 && result4->left->right->val == 6 &&
            result4->right->left->val == 3 && result4->right->right->val == 1
                ? "Passed"
                : "Failed")
        << endl;
    return 0;
}
