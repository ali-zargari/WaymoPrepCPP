#include <iostream>
// #include <queue> // Not used
#include <string>
#include <vector> // Not used
#include <unordered_map>
// #include <unordered_set> // Not used
#include <limits> // For numeric_limits
#include <stack>

using namespace std;

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

class Solution
{
public:
    // can either use a global variable.
    // can also use a helper function which has an integer parameter.
    // can also use an iterative method using a stack for DFS. let's use this method.

    int maxDepthIterate(TreeNode* root) //DFS
    {
        if (!root)
            return 0;

        stack<pair<TreeNode*, int>> st;

        st.push({root, 1});
        int res = 1;

        while (!st.empty())
        {
            TreeNode* curr = st.top().first;
            int curr_depth = st.top().second;

            st.pop();


            res = max(res, curr_depth);

            if (curr->right)
            {
                st.push({curr->right, curr_depth + 1});
            }

            if (curr->left)
            {
                st.push({curr->left, curr_depth + 1});
            }
        }

        return res;
    }


    int maxDepth(TreeNode* root) //DFS
    {
        if (!root)
        {
            return 0;
        }

        int left = maxDepth(root->left) + 1;
        int right = maxDepth(root->right) + 1;

        return max(left, right);

    }
};


// Main function provided by user - unchanged.
int main()
{
    Solution s;


    // Test case 1: Empty tree (root is nullptr)
    TreeNode* root1 = nullptr;
    cout << "Test case 1 (Empty tree): " << s.maxDepth(root1) << endl; // Expected output: 0

    // Test case 2: Single-node tree
    TreeNode* root2 = new TreeNode(1);
    cout << "Test case 2 (Single-node tree): " << s.maxDepth(root2) << endl; // Expected output: 1

    // Test case 3: Tree with two levels
    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    cout << "Test case 3 (Two levels): " << s.maxDepth(root3) << endl; // Expected output: 2

    // Test case 4: Tree with three levels
    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(3);
    root4->left->left = new TreeNode(4);
    root4->left->right = new TreeNode(5);
    root4->right->right = new TreeNode(6);
    cout << "Test case 4 (Three levels): " << s.maxDepth(root4) << endl; // Expected output: 3

    // Test case 5: Skewed tree (all nodes to the left)
    TreeNode* root5 = new TreeNode(1);
    root5->left = new TreeNode(2);
    root5->left->left = new TreeNode(3);
    root5->left->left->left = new TreeNode(4);
    cout << "Test case 5 (Left-skewed tree): " << s.maxDepth(root5) << endl; // Expected output: 4

    // Test case 6: Skewed tree (all nodes to the right)
    TreeNode* root6 = new TreeNode(1);
    root6->right = new TreeNode(2);
    root6->right->right = new TreeNode(3);
    root6->right->right->right = new TreeNode(4);
    cout << "Test case 6 (Right-skewed tree): " << s.maxDepth(root6) << endl; // Expected output: 4


    return 0;
}
