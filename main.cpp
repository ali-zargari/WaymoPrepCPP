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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {

        if (p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }

        return root;

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

    // Test cases for lowestCommonAncestor
    // Helper lambda to display TreeNode's value
    auto displayResult = [](TreeNode* node)
    {
        if (node)
        {
            cout << "Lowest Common Ancestor: " << node->val << endl;
        }
        else
        {
            cout << "Lowest Common Ancestor: nullptr" << endl;
        }
    };

    // Test Case 1: Basic BST
    vector<int> values1 = {6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5};
    TreeNode* root1 = createTree(values1);
    TreeNode* p1 = root1->left; // Node 2
    TreeNode* q1 = root1->right; // Node 8
    TreeNode* result1 = s.lowestCommonAncestor(root1, p1, q1);
    cout << "Test Case 1: Expected: 6, Got: ";
    displayResult(result1);

    // Test Case 2: Both p and q are in the left subtree
    TreeNode* p2 = root1->left->right->left; // Node 3
    TreeNode* q2 = root1->left->right->right; // Node 5
    TreeNode* result2 = s.lowestCommonAncestor(root1, p2, q2);
    cout << "Test Case 2: Expected: 4, Got: ";
    displayResult(result2);

    // Test Case 3: One node is an ancestor of the other
    TreeNode* p3 = root1->left; // Node 2
    TreeNode* q3 = root1->left->right; // Node 4
    TreeNode* result3 = s.lowestCommonAncestor(root1, p3, q3);
    cout << "Test Case 3: Expected: 2, Got: ";
    displayResult(result3);

    // Test Case 4: Both nodes are in the right subtree
    TreeNode* p4 = root1->right->left; // Node 7
    TreeNode* q4 = root1->right->right; // Node 9
    TreeNode* result4 = s.lowestCommonAncestor(root1, p4, q4);
    cout << "Test Case 4: Expected: 8, Got: ";
    displayResult(result4);

    // Test Case 5: p and q are the same node
    TreeNode* p5 = root1->left->right; // Node 4
    TreeNode* q5 = root1->left->right; // Node 4
    TreeNode* result5 = s.lowestCommonAncestor(root1, p5, q5);
    cout << "Test Case 5: Expected: 4, Got: ";
    displayResult(result5);

    // Test Case 6: Both p and q are root
    TreeNode* p6 = root1; // Root Node 6
    TreeNode* q6 = root1; // Root Node 6
    TreeNode* result6 = s.lowestCommonAncestor(root1, p6, q6);
    cout << "Test Case 6: Expected: 6, Got: ";
    displayResult(result6);

    // Test Case 7: p and q are in opposite extreme leaf positions
    TreeNode* p7 = root1->left->left; // Node 0
    TreeNode* q7 = root1->right->right; // Node 9
    TreeNode* result7 = s.lowestCommonAncestor(root1, p7, q7);
    cout << "Test Case 7: Expected: 6, Got: ";
    displayResult(result7);

    // Test Case 8: Invalid tree with one node
    TreeNode* root2 = new TreeNode(1);
    TreeNode* p8 = root2; // Node 1
    TreeNode* q8 = root2; // Node 1
    TreeNode* result8 = s.lowestCommonAncestor(root2, p8, q8);
    cout << "Test Case 8: Expected: 1, Got: ";
    displayResult(result8);

    // Test Case 9: Non-consecutive nodes that don't form an ancestor relationship in BST
    TreeNode* p9 = root1->left->left; // Node 0
    TreeNode* q9 = root1->left->right; // Node 4
    TreeNode* result9 = s.lowestCommonAncestor(root1, p9, q9);
    cout << "Test Case 9: Expected: 2, Got: ";
    displayResult(result9);

    // Test Case 10: Tree is empty
    TreeNode* root3 = nullptr;
    TreeNode* p10 = nullptr;
    TreeNode* q10 = nullptr;
    TreeNode* result10 = s.lowestCommonAncestor(root3, p10, q10);
    cout << "Test Case 10: Expected: nullptr, Got: ";
    displayResult(result10);

    return 0;
}
