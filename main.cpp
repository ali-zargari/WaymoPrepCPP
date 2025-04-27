#include <iostream>
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


class Solution {
public:
    bool isValidBST(TreeNode* root) {

        vector<int> res;

        return dfs(root, res);
    }

    bool dfs(TreeNode* root, vector<int>& res)
    {
        if (!root)
        {
            return true;
        }

        if (!dfs(root->left, res))
        {
            return false;
        }

        res.push_back(root->val);

        if (res.size() >= 2 && res[res.size()-1] <= res[res.size()-2])
        {
            return false;
        }

        return dfs(root->right, res);
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


    // Test case: Valid Binary Search Tree
    vector<int> values1 = {2, 1, 3}; // A valid BST
    TreeNode* root1 = createTree(values1);
    bool result1 = s.isValidBST(root1);
    cout << "Test Case 1 - Is Valid BST: " << (result1 ? "True" : "False") << " (Expected: True)" << endl;
    cout << "Tree 1 Structure:" << endl;
    cout << "    2" << endl;
    cout << "   / \\" << endl;
    cout << "  1   3" << endl;

    /*// Test case: Invalid Binary Search Tree
    vector<int> values2 = {5, 1, 4, -1, -1, 3, 6}; // An invalid BST
    TreeNode* root2 = createTree(values2);
    bool result2 = s.isValidBST(root2);
    cout << "Test Case 2 - Is Valid BST: " << (result2 ? "True" : "False") << " (Expected: False)" << endl;
    cout << "Tree 2 Structure:" << endl;
    cout << "        5" << endl;
    cout << "       / \\" << endl;
    cout << "      1   4" << endl;
    cout << "         / \\" << endl;
    cout << "        3   6" << endl;

    // Test case: Empty tree
    TreeNode* root3 = nullptr; // An empty tree
    bool result3 = s.isValidBST(root3);
    cout << "Test Case 3 - Is Valid BST: " << (result3 ? "True" : "False") << " (Expected: True)" << endl;
    cout << "Tree 3 Structure: Empty Tree" << endl;

    // Cleaning up allocated memory
    delete root1;
    delete root2;
    // No need to delete root3 as it's nullptr*/

    return 0;
}
