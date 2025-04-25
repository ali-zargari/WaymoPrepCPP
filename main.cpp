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


    bool isSameTree(TreeNode* p, TreeNode* q)
    {

        if (!p && !q)
        {
            return true;
        }

        if (p && q && p->val == q->val)
        {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }

        return false;
    }


    bool isSameTreeIter(TreeNode* p, TreeNode* q)
    {

        stack<pair<TreeNode*, TreeNode*>> stk;
        stk.emplace(p, q);

        while (!stk.empty())
        {

            pair curr = {stk.top().first, stk.top().second};
            stk.pop();

            if (!curr.first && !curr.second)
            {
                continue;
            }

            if (!curr.first || !curr.second)
            {
                return false;
            }

            if (curr.first->val != curr.second->val)
            {
                return false;
            }

            stk.emplace(curr.first->right, curr.second->right);
            stk.emplace(curr.first->left, curr.second->left);


        }

        return true;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {

        stack <pair<TreeNode*, TreeNode*>> stk;
        stk.emplace(root, subRoot);

        if (!root && subRoot)
        {
            return false;
        }

        if (!subRoot && root)
        {
            return false;
        }

        if (!subRoot && !root)
        {
            return true;
        }

        while (!stk.empty())
        {

            pair curr = stk.top();
            stk.pop();

            if (curr.first->val == curr.second->val)
            {
                stack <pair<TreeNode*, TreeNode*>> check_stk;
                check_stk.push(curr);
                bool match = true;

                while (!check_stk.empty())
                {
                    pair checking_curr = check_stk.top();
                    check_stk.pop();

                    if (!checking_curr.first && !checking_curr.second)
                    {
                        continue;
                    }

                    if (!checking_curr.first || !checking_curr.second)
                    {
                        match = false;
                        break;
                    }

                    if (checking_curr.first->val != checking_curr.second->val)
                    {
                        match = false;
                        break;
                    }


                    check_stk.emplace(checking_curr.first->right, checking_curr.second->right);
                    check_stk.emplace(checking_curr.first->left, checking_curr.second->left);
                }

                if (match)
                {
                    return true;
                }
            }

            if (curr.first->right)
                stk.emplace(curr.first->right, subRoot);

            if (curr.first->left)
                stk.emplace(curr.first->left, subRoot);
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
