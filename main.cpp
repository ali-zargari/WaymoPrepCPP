#include <iostream>
#include <queue>
#include <stack>
#include <stdint.h>
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


    vector<int> preOrder(TreeNode* root)
    {
        TreeNode* node;
        stack<TreeNode*> stk;
        vector<int> res;

        stk.push(root);

        while (!stk.empty())
        {
            TreeNode* node = stk.top();
            stk.pop();
            res.push_back(node->val);

            if (node->right)
            {
                stk.push(node->right);
            }
            if (node->left)
            {
                stk.push(node->left);
            }
        }

        return res;
    }



    vector<int> bfs(TreeNode* root)
    {
        TreeNode* node;
        queue<TreeNode*> q;
        vector<int> res;

        q.push(root);

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            res.push_back(node->val);

            if (node->left)
            {
                q.push(node->left);
            }

            if (node->right)
            {
                q.push(node->right);
            }

        }

        return res;
    }



    vector<int> inOrder(TreeNode* root)
    {
        TreeNode* node = root;
        stack<TreeNode*> stk;
        vector<int> res;

        while (!stk.empty() || node)
        {
            
            while (node)
            {
                stk.push(node);
                node = node->left;
            }

            node = stk.top();
            stk.pop();
            res.push_back(node->val);

            node = node->right;
            
        }
        return res;
    }

    
    vector<int> postOrder(TreeNode* root)
    {
        TreeNode* node;
        stack<TreeNode*> stk;
        stack<TreeNode*> stk2;
        vector<int> res;

        stk.push(root);

        while (!stk.empty())
        {
            TreeNode* node = stk.top();
            stk.pop();
            stk2.push(node);

            if (node->left)
            {
                stk.push(node->left);
            }

            if (node->right)
            {
                stk.push(node->right);
            }

        }

        while (!stk2.empty())
        {
            res.push_back(stk2.top()->val);
            stk2.pop();
        }

        return res;
    }


    int goodNodes(TreeNode* root) {
        //This looks like a DFS function. We keep going down the nodes. We can do it iteratively. While going down, we
        //keep the maximum val node we have found in that path (can use a stack). Use max() function to keep track of highest value in path.
        //This is missing a part of the logic because we are doing pre-order traversal. But if we do Post order, then we can effectively see
        //which children are larger.
        
        stack<TreeNode*> stk;
        stack<TreeNode*> max_nodes;
        int max = INT32_MIN;
        int count = 0;
        
        stk.push(root);
        max_nodes.push(root);
        
        while (!stk.empty())
        {
            TreeNode* node = stk.top();
            
            
            if (!max_nodes.empty() && node->val >= max_nodes.top()->val)
            {
                count ++;
                max_nodes.push(node);
                //max = node->val;
            }
            
            stk.pop();

            if (node->right)
            {
                stk.push(node->right);
            }
            if (node->left)
            {
                stk.push(node->left);
            }
        }
        return count;
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


    // Create a binary tree:
    //         5
    //       /   \
    //      3     7
    //     / \   / \
    //    2   4 6   8
    vector<int> treeValues = {5, 3, 7, 2, 4, 6, 8};
    TreeNode* root = createTree(treeValues);

    // Expected results
    vector<int> expectedPreOrder = {5, 3, 2, 4, 7, 6, 8};
    vector<int> expectedBFS = {5, 3, 7, 2, 4, 6, 8};
    vector<int> expectedInOrder = {2, 3, 4, 5, 6, 7, 8};

    // Call preOrder
    vector<int> result = s.preOrder(root);

    // Compare and print
    cout << "preOrder traversal: [";
    for (size_t i = 0; i < result.size(); ++i)
    {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Expected: [";
    for (size_t i = 0; i < expectedPreOrder.size(); ++i)
    {
        cout << expectedPreOrder[i];
        if (i < expectedPreOrder.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << endl;

    // Call bfs
    result = s.bfs(root);

    // Compare and print
    cout << "BFS traversal: [";
    for (size_t i = 0; i < result.size(); ++i)
    {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Expected: [";
    for (size_t i = 0; i < expectedBFS.size(); ++i)
    {
        cout << expectedBFS[i];
        if (i < expectedBFS.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << endl;

    // Call inOrder
    result = s.inOrder(root);

    // Compare and print
    cout << "inOrder traversal: [";
    for (size_t i = 0; i < result.size(); ++i)
    {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Expected: [";
    for (size_t i = 0; i < expectedInOrder.size(); ++i)
    {
        cout << expectedInOrder[i];
        if (i < expectedInOrder.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << endl;

    // Call postOrder
    result = s.postOrder(root);

    // Compare and print
    cout << "postOrder traversal: [";
    for (size_t i = 0; i < result.size(); ++i)
    {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    // Expected post-order traversal
    vector<int> expectedPostOrder = {2, 4, 3, 6, 8, 7, 5};

    cout << "Expected: [";
    for (size_t i = 0; i < expectedPostOrder.size(); ++i)
    {
        cout << expectedPostOrder[i];
        if (i < expectedPostOrder.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
