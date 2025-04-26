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

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root) {


        if (!root)
        {
            return vector<vector<int>>();
        }

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> res;

        int index = 0;

        while (!q.empty())
        {


            res.push_back(vector<int>());
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                res[index].push_back(node->val);

                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }


            index++;

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


    // Test cases
    vector<pair<vector<int>, vector<vector<int>>>> testCases = {
        {{3, 9, 20, -1, -1, 15, 7}, {{3}, {9, 20}, {15, 7}}}, // Test Case 1
        {{1}, {{1}}}, // Test Case 2 (single-node tree)
        {{}, {}}, // Test Case 3 (empty tree)
        {{1, 2, 3, 4, 5, 6, 7}, {{1}, {2, 3}, {4, 5, 6, 7}}} // Test Case 4 (complete binary tree)
    };

    for (size_t i = 0; i < testCases.size(); ++i)
    {
        const auto& [treeValues, expected] = testCases[i];

        TreeNode* root = createTree(treeValues);
        vector<vector<int>> output = s.levelOrder(root);

        cout << "Test Case " << i + 1 << ":\n";
        cout << "Input Tree: ";
        for (int val : treeValues) cout << val << " ";
        cout << "\nExpected Output: ";
        for (const auto& level : expected)
        {
            cout << "[";
            for (int val : level)
                cout << val << " ";
            cout << "]";
        }
        cout << "\nActual Output: ";
        for (const auto& level : output)
        {
            cout << "[";
            for (int val : level)
                cout << val << " ";
            cout << "]";
        }
        cout << "\n\n";

        // Clean up dynamically allocated tree
        delete root;
    }


    return 0;
}
