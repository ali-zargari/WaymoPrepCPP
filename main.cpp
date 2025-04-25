#include <iostream>
#include <string>
#include <vector>


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

    int dfs(TreeNode* root, bool& balanced)
    {
        if (!root)
        {
            return true;
        }

        int left = dfs(root->left, balanced);
        int right = dfs(root->right, balanced);

        if (abs(left-right) > 1)
        {
            balanced = false;
        }

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        if (!root)
        {
            return true;
        }

        bool balanced = true;

        dfs(root, balanced);

        return balanced;

    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q){
            return true;
        }

        if (p == nullptr && q != nullptr) {
            return false;
        }

        if (q == nullptr && p != nullptr) {
            return false;
        }

        if (p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);


        return false;

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
    cout << "Test Case 1: Empty tree" << endl;
    cout << "Diameter: " << s.diameterOfBinaryTree(root1) << endl;
    cout << "Depth: " << s.depth(root1) << endl;
    cout << "Is Balanced: " << (s.isBalanced(root1) ? "Yes" : "No") << endl;
    cout << "--------------------------" << endl;

    // Test case 2: Single node tree
    TreeNode* root2 = new TreeNode(1);
    cout << "Test Case 2: Single node tree" << endl;
    cout << "Diameter: " << s.diameterOfBinaryTree(root2) << endl;
    cout << "Depth: " << s.depth(root2) << endl;
    cout << "Is Balanced: " << (s.isBalanced(root2) ? "Yes" : "No") << endl;
    cout << "--------------------------" << endl;

    // Test case 3: Balanced binary tree
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    TreeNode* root3 = createTree({1, 2, 3, 4, 5});
    cout << "Test Case 3: Balanced binary tree" << endl;
    cout << "Diameter: " << s.diameterOfBinaryTree(root3) << endl;
    cout << "Depth: " << s.depth(root3) << endl;
    cout << "Is Balanced: " << (s.isBalanced(root3) ? "Yes" : "No") << endl;
    cout << "--------------------------" << endl;

    // Test case 4: Linear tree (skewed to the left)
    //      1
    //     /
    //    2
    //   /
    //  3
    TreeNode* root4 = createTree({1, 2, -1, 3});
    cout << "Test Case 4: Left-skewed tree" << endl;
    cout << "Diameter: " << s.diameterOfBinaryTree(root4) << endl;
    cout << "Depth: " << s.depth(root4) << endl;
    cout << "Is Balanced: " << (s.isBalanced(root4) ? "Yes" : "No") << endl;
    cout << "--------------------------" << endl;

    // Test case 5: Linear tree (skewed to the right)
    // 1
    //  \
    //   2
    //    \
    //     3
    TreeNode* root5 = createTree({1, -1, 2, -1, -1, -1, 3});
    cout << "Test Case 5: Right-skewed tree" << endl;
    cout << "Diameter: " << s.diameterOfBinaryTree(root5) << endl;
    cout << "Depth: " << s.depth(root5) << endl;
    cout << "Is Balanced: " << (s.isBalanced(root5) ? "Yes" : "No") << endl;
    cout << "--------------------------" << endl;

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
    cout << "Test Case 6: Unbalanced binary tree" << endl;
    cout << "Diameter: " << s.diameterOfBinaryTree(root6) << endl;
    cout << "Depth: " << s.depth(root6) << endl;
    cout << "Is Balanced: " << (s.isBalanced(root6) ? "Yes" : "No") << endl;
    cout << "--------------------------" << endl;


    // Test case 7: Symmetrical but unbalanced binary tree
    //      1
    //     / \
    //    2   2
    //   /     \
    //  3       3
    // /         \
    // 4           4
    TreeNode* root7 = createTree({1, 2, 2, 3, -1, -1, 3, 4, -1, -1, 4});
    cout << "Test Case 7: Symmetrical but unbalanced binary tree" << endl;
    cout << "Diameter: " << s.diameterOfBinaryTree(root7) << endl;
    cout << "Depth: " << s.depth(root7) << endl;
    cout << "Is Balanced: " << (s.isBalanced(root7) ? "Yes" : "No") << endl;
    cout << "--------------------------" << endl;


    // Test case 8: Identical trees
    TreeNode* p1 = createTree({1, 2, 3});
    TreeNode* q1 = createTree({1, 2, 3});
    cout << "Test Case 8: Identical trees" << endl;
    cout << "Is Same Tree: " << (s.isSameTree(p1, q1) ? "Yes" : "No") << endl;
    cout << "--------------------------" << endl;

    // Test case 9: Different trees (structure)
    TreeNode* p2 = createTree({1, 2});
    TreeNode* q2 = createTree({1, -1, 2});
    cout << "Test Case 9: Different trees (structure)" << endl;
    cout << "Is Same Tree: " << (s.isSameTree(p2, q2) ? "Yes" : "No") << endl;
    cout << "--------------------------" << endl;

    // Test case 10: Different trees (values)
    TreeNode* p3 = createTree({1, 2, 1});
    TreeNode* q3 = createTree({1, 1, 2});
    cout << "Test Case 10: Different trees (values)" << endl;
    cout << "Is Same Tree: " << (s.isSameTree(p3, q3) ? "Yes" : "No") << endl;
    cout << "--------------------------" << endl;

    return 0;
}
