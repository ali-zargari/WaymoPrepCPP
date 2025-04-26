#include <iostream>
#include <queue>
#include <stack>
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


class Solution {
public:
    // we can do an in-order traversal
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        return dfs(root, res, k);
        //return res[k];
    }

    int dfs(TreeNode* root, vector<int>& res, int k)
    {
        if (!root)
        {
            return 0;
        }

        int val = dfs(root->left, res, k);

        if (val)
        {
            return val;
        }

        res.push_back(root->val);

        if (res.size() == k)
            return res.back();

        return dfs(root->right, res, k);
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


    // Test cases for the kthSmallest function
    vector<int> treeValues = {3, 1, 4, -1, 2}; // -1 represents null nodes
    TreeNode* root = createTree(treeValues);

    int k = 1; // Example input to find the 1st smallest
    cout << "Test 1 - k = " << k << ": " << s.kthSmallest(root, k) << " (Expected: 1)" << endl;

    k = 2; // Example to find the 2nd smallest
    cout << "Test 2 - k = " << k << ": " << s.kthSmallest(root, k) << " (Expected: 2)" << endl;

    k = 3; // Example to find the 3rd smallest
    cout << "Test 3 - k = " << k << ": " << s.kthSmallest(root, k) << " (Expected: 3)" << endl;

    k = 4; // Example to find the 4th smallest
    cout << "Test 4 - k = " << k << ": " << s.kthSmallest(root, k) << " (Expected: 4)" << endl;

    // Don't forget to free the allocated memory after tests
    
    return 0;
}
