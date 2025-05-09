#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
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
    vector<string> generateParenthesis(int n)
    {
        string str = "";

        for (int i = 0; i < n; i++)
        {
            str += "(";
        }

        for (int i = 0; i < n; i++)
        {
            str += ")";
        }

        struct Frame
        {
            int open;
            int close;
            string comb;
        };


        stack<Frame> stk;
        stk.push({0, 0, ""});
        vector<string> res;

        while (!stk.empty())
        {
            Frame curr = stk.top();
            stk.pop();
            int open = curr.open;
            int close = curr.close;
            string comb = curr.comb;

            if (comb.size() > n*2) continue;

            if (open != 0 && open == close && comb.size() == 2*n)
            {
                res.push_back(comb);
            }

            if (open < n)
                stk.push({open + 1, close, comb + "("});

            if (open > close)
                stk.push({open, close + 1, comb + ")"});

        }

        return res;
    }
};


// Main function provided by user - unchanged.
int main()
{
    Solution s;

    vector<string> result = s.generateParenthesis(10);
    for (const auto& p : result)
    {
        cout << p << endl;
    }
    return 0;
}
