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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        if (!root)
        {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;


        while (!q.empty())
        {

            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                node = q.front();
                q.pop();

                if (node->left)
                {
                    q.push(node->left);
                }

                if (node->right)
                {
                    q.push(node->right);
                }

                if (i == size-1)
                {
                    res.push_back(node->val);
                }

            }

        }

        return res;
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


    // Test Case 1: Simple binary tree
    vector<int> values1 = {1, 2, 3, -1, 5, -1, 4};
    TreeNode* root1 = createTree(values1);
    vector<int> result1 = s.rightSideView(root1);
    cout << "Right Side View (Test Case 1): ";
    for (int val : result1)
    {
        cout << val << " ";
    }
    cout << endl;

    // Test Case 2: Binary tree with only root node
    vector<int> values2 = {1};
    TreeNode* root2 = createTree(values2);
    vector<int> result2 = s.rightSideView(root2);
    cout << "Right Side View (Test Case 2): ";
    for (int val : result2)
    {
        cout << val << " ";
    }
    cout << endl;

    // Test Case 3: Empty binary tree
    vector<int> values3 = {};
    TreeNode* root3 = createTree(values3);
    vector<int> result3 = s.rightSideView(root3);
    cout << "Right Side View (Test Case 3): ";
    for (int val : result3)
    {
        cout << val << " ";
    }
    cout << endl;

    // Test Case 4: Left-skewed binary tree
    vector<int> values4 = {1, 2, -1, 3, -1, -1, -1};
    TreeNode* root4 = createTree(values4);
    vector<int> result4 = s.rightSideView(root4);
    cout << "Right Side View (Test Case 4): ";
    for (int val : result4)
    {
        cout << val << " ";
    }
    cout << endl;

    // Test Case 5: Right-skewed binary tree
    vector<int> values5 = {1, -1, 2, -1, -1, -1, 3};
    TreeNode* root5 = createTree(values5);
    vector<int> result5 = s.rightSideView(root5);
    cout << "Right Side View (Test Case 5): ";
    for (int val : result5)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
