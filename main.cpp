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
    //We can do a postorder DFS. This way we compute the children, and compare to parents.
    //
    int goodNodes(TreeNode* root)
    {

        int res = dfs(root, INT_MIN);

        return res;
    }


    int dfs(TreeNode* root, int path_max)
    {

        if (!root)
        {
            return 0;
        }

        int left = dfs(root->left, max(path_max, root->val));
        int right = dfs(root->right, max(path_max, root->val));


        if (root->val >= path_max)
        {
            return left + right + 1;
        }
        return left + right;


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


    // Test case 1: Single node tree
    {
        TreeNode* root = createTree({3});
        int actual = s.goodNodes(root);
        int expected = 1;
        cout << "Test case 1: " << (actual == expected ? "Passed" : "Failed")
            << " (Actual: " << actual << ", Expected: " << expected << ")" << endl;
        delete root;
    }

    // Test case 2: All nodes are good nodes (strictly increasing values in path)
    {
        TreeNode* root = createTree({3, 2, 4, 1, -1, 5});
        int actual = s.goodNodes(root);
        int expected = 3;
        cout << "Test case 2: " << (actual == expected ? "Passed" : "Failed")
            << " (Actual: " << actual << ", Expected: " << expected << ")" << endl;
        delete root;
    }

    // Test case 3: Only root is a good node
    {
        TreeNode* root = createTree({3, 2, 1});
        int actual = s.goodNodes(root);
        int expected = 1;
        cout << "Test case 3: " << (actual == expected ? "Passed" : "Failed")
            << " (Actual: " << actual << ", Expected: " << expected << ")" << endl;
        delete root;
    }

    // Test case 4: All nodes are bad except the root
    {
        TreeNode* root = createTree({3, 1, 1, 0});
        int actual = s.goodNodes(root);
        int expected = 1;
        cout << "Test case 4: " << (actual == expected ? "Passed" : "Failed")
            << " (Actual: " << actual << ", Expected: " << expected << ")" << endl;
        delete root;
    }

    // Test case 5: Mixed case
    {
        TreeNode* root = createTree({3, 3, 4, 2, 1, 5});
        int actual = s.goodNodes(root);
        int expected = 3;
        cout << "Test case 5: " << (actual == expected ? "Passed" : "Failed")
            << " (Actual: " << actual << ", Expected: " << expected << ")" << endl;
        delete root;
    }

    // Test case 6: Empty tree
    {
        TreeNode* root = nullptr;
        int actual = s.goodNodes(root);
        int expected = 0;
        cout << "Test case 6: " << (actual == expected ? "Passed" : "Failed")
            << " (Actual: " << actual << ", Expected: " << expected << ")" << endl;
    }

    return 0;
}
