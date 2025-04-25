#include <iostream>
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

        return max(depth(root->left) + 1, depth(root->right) + 1);
    }

    int dfs(TreeNode* root, int& res)
    {
        if (!root)
        {
            return 0;
        }

        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        res = max(res, left + right);
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

        if (abs(left - right) > 1)
        {
            balanced = false;
        }

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root)
    {
        if (!root)
        {
            return true;
        }

        bool balanced = true;

        dfs(root, balanced);

        return balanced;
    }

    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (!p && !q)
        {
            return true;
        }

        if (p == nullptr && q != nullptr)
        {
            return false;
        }

        if (q == nullptr && p != nullptr)
        {
            return false;
        }

        if (p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);


        return false;
    }


    bool isSameTreeIter(TreeNode* p, TreeNode* q)
    {
        if (!p && !q)
        {
            return true;
        }

        if (p == nullptr && q != nullptr)
        {
            return false;
        }

        if (q == nullptr && p != nullptr)
        {
            return false;
        }

        if (p->val == q->val)
        {
            stack<pair<TreeNode*, TreeNode*>> node_stack;
            node_stack.push({p, q});

            while (!node_stack.empty())
            {
                auto [first, second] = node_stack.top();
                node_stack.pop();

                if (!first && !second) continue;

                if (!first || !second || first->val != second->val)
                {
                    return false;
                }

                node_stack.push({first->right, second->right});
                node_stack.push({first->left, second->left});
            }
        }
        return true;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if (!root && !subRoot)
        {
            return true;
        }

        if (!root && subRoot)
        {
            return false;
        }

        if (root && !subRoot)
        {
            return false;
        }

        stack<TreeNode*> node_stack;
        node_stack.push(root);

        while (!node_stack.empty())
        {
            TreeNode* curr = node_stack.top();
            node_stack.pop();

            if (curr->val == subRoot->val)
            {
                bool match = true;

                // rename this so it doesn’t shadow:
                stack<pair<TreeNode*, TreeNode*>> compare_stack;
                // no need for curr_copy; we seed the pair directly
                compare_stack.push({curr, subRoot});

                while (!compare_stack.empty())
                {
                    auto [main_node, sub_node] = compare_stack.top();
                    compare_stack.pop();

                    if (!main_node && !sub_node) continue;
                    if (!main_node || !sub_node || main_node->val != sub_node->val)
                    {
                        match = false;
                        break;
                    }

                    // push children in lock-step
                    compare_stack.push({main_node->right, sub_node->right});
                    compare_stack.push({main_node->left, sub_node->left});
                }

                if (match) return true;
            }
            else
            {
                if (curr->right)
                {
                    node_stack.push(curr->right);
                }

                if (curr->left)
                {
                    node_stack.push(curr->left);
                }
            }
        }

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
    cout << "Is Same Tree: " << (s.isSameTreeIter(p1, q1) ? "Yes" : "No") << endl;
    cout << "--------------------------" << endl;

    // Test case 9: Different trees (structure)
    TreeNode* p2 = createTree({1, 2});
    TreeNode* q2 = createTree({1, -1, 2});
    cout << "Test Case 9: Different trees (structure)" << endl;
    cout << "Is Same Tree: " << (s.isSameTreeIter(p2, q2) ? "Yes" : "No") << endl;
    cout << "--------------------------" << endl;

    // Test case 10: Different trees (values)
    TreeNode* p3 = createTree({1, 2, 1});
    TreeNode* q3 = createTree({1, 1, 2});
    cout << "Test Case 10: Different trees (values)" << endl;
    cout << "Is Same Tree: " << (s.isSameTreeIter(p3, q3) ? "Yes" : "No") << endl;
    cout << "--------------------------" << endl;


    // Test case 11: subtree
    // Tree S:
    //      3
    //     / \
    //    4   5
    //   / \
    //  1   2
    //
    // Tree T:
    //    4
    //   / \
    //  1   2
    TreeNode* S1 = createTree({1, 1});
    TreeNode* T1 = createTree({1});
    cout << "Test Case 11: T is a subtree of S" << endl;
    cout << "Is Subtree: " << (s.isSubtree(S1, T1) ? "Yes" : "No") << endl;
    cout << "--------------------------" << endl;

    // Test case 12: T is not a subtree of S
    // Tree S:
    //      3
    //     / \
    //    4   5
    //   / \
    //  1   2
    //
    // Tree T:
    //    4
    //   /
    //  1
    TreeNode* S2 = createTree({3, 4, 5, 1, 2});
    TreeNode* T2 = createTree({4, 1});
    cout << "Test Case 12: T is not a subtree of S" << endl;
    cout << "Is Subtree: " << (s.isSubtree(S2, T2) ? "Yes" : "No") << endl;
    cout << "--------------------------" << endl;

    // Test case 13: T is identical to S
    // Tree S:
    //      3
    //     / \
    //    4   5
    TreeNode* S3 = createTree({3, 4, 5});
    TreeNode* T3 = createTree({3, 4, 5});
    cout << "Test Case 13: T is identical to S" << endl;
    cout << "Is Subtree: " << (s.isSubtree(S3, T3) ? "Yes" : "No") << endl;
    cout << "--------------------------" << endl;

    // Test case 14: S is empty, T is not
    TreeNode* S4 = nullptr;
    TreeNode* T4 = createTree({1});
    cout << "Test Case 14: S is empty, T is not" << endl;
    cout << "Is Subtree: " << (s.isSubtree(S4, T4) ? "Yes" : "No") << endl;
    cout << "--------------------------" << endl;

    // Test case 15: T is empty
    TreeNode* S5 = createTree({1, 2, 3});
    TreeNode* T5 = nullptr;
    cout << "Test Case 15: T is empty" << endl;
    cout << "Is Subtree: " << (s.isSubtree(S5, T5) ? "Yes" : "No") << endl;
    cout << "--------------------------" << endl;

    // Test case 16: Both S and T are empty
    TreeNode* S6 = nullptr;
    TreeNode* T6 = nullptr;
    cout << "Test Case 16: Both S and T are empty" << endl;
    cout << "Is Subtree: " << (s.isSubtree(S6, T6) ? "Yes" : "No") << endl;
    cout << "--------------------------" << endl;


    // Test case 17: Non-matching subtree
    // Tree S:
    //      3
    //     / \
    //    4   5
    //   / \
    //  1   2
    //
    // Tree T:
    //    4
    //   / \
    //  1   3
    TreeNode* S7 = createTree({3, 4, 5, 1, 2});
    TreeNode* T7 = createTree({4, 1, 3});
    cout << "Test Case 17: T is not a matching subtree of S" << endl;
    cout << "Is Subtree: " << (s.isSubtree(S7, T7) ? "Yes" : "No") << endl;
    cout << "--------------------------" << endl;

    return 0;
}
