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
    

    int diameterOfBinaryTree(TreeNode* root) //DFS
    {
        int len = 0;
        dfs(root, len);
        return len;

    }

    int depth(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }

        return max(depth(root->left)+1,  depth(root->right)+1);
    }

    int dfs(TreeNode* root, int& res)
    {
        if (!root)
        {
            return 0;
        }

        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        res = max(res, left+right);
        return 1 + max(left, right);
    }
};



// Helper function to create a binary tree
TreeNode* createTree(const vector<int>& values, int index = 0)
{
    if (index >= values.size() || values[index] == -1)
    {
        // -1 represents a null node
        return nullptr;
    }
    auto* root = new TreeNode(values[index]);
    root->left = createTree(values, 2 * index + 1);
    root->right = createTree(values, 2 * index + 2);
    return root;
}

// Main function provided by user - unchanged.
int main()
{
    Solution s;



    // Test case 1: Empty tree
    TreeNode* root1 = nullptr;
    cout << "Test Case 1: Diameter of empty tree: " << s.diameterOfBinaryTree(root1) << endl;
    cout << "Test Case 1: Depth of empty tree: " << s.depth(root1) << endl;

    // Test case 2: Single node tree
    TreeNode* root2 = new TreeNode(1);
    cout << "Test Case 2: Diameter of single node tree: " << s.diameterOfBinaryTree(root2) << endl;
    cout << "Test Case 2: Depth of single node tree: " << s.depth(root2) << endl;

    // Test case 3: Balanced binary tree
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    TreeNode* root3 = createTree({1, 2, 3, 4, 5});
    cout << "Test Case 3: Diameter of balanced binary tree: " << s.diameterOfBinaryTree(root3) << endl;
    cout << "Test Case 3: Depth of balanced binary tree: " << s.depth(root3) << endl;

    // Test case 4: Linear tree (skewed to the left)
    //      1
    //     /
    //    2
    //   /
    //  3
    TreeNode* root4 = createTree({1, 2, -1, 3});
    cout << "Test Case 4: Diameter of left-skewed tree: " << s.diameterOfBinaryTree(root4) << endl;
    cout << "Test Case 4: Depth of left-skewed tree: " << s.depth(root4) << endl;

    // Test case 5: Linear tree (skewed to the right)
    // 1
    //  \
    //   2
    //    \
    //     3
    TreeNode* root5 = createTree({1, -1, 2, -1, -1, -1, 3});
    cout << "Test Case 5: Diameter of right-skewed tree: " << s.diameterOfBinaryTree(root5) << endl;
    cout << "Test Case 5: Depth of right-skewed tree: " << s.depth(root5) << endl;

    // Test case 6: Unbalanced binary tree
    //      1
    //     / \
    //    2   3
    //   /
    //  4
    //   \
    //    5
    //     \
    //      6
    TreeNode* root6 = createTree({1, 2, 3, 4, -1, -1, -1, -1, 5, -1, -1, -1, -1, -1, 6});
    cout << "Test Case 6: Diameter of unbalanced binary tree: " << s.diameterOfBinaryTree(root6) << endl;
    cout << "Test Case 6: Depth of unbalanced binary tree: " << s.depth(root6) << endl;


    return 0;
}
