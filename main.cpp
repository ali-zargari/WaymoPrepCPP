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
    vector<string> letterCombinations(string digits)
    {
        unordered_map<int, vector<char>> adj;

        adj[2] = {'a', 'b', 'c'};
        adj[3] = {'d', 'e', 'f'};
        adj[4] = {'g', 'h', 'i'};
        adj[5] = {'j', 'k', 'l'};
        adj[6] = {'m', 'n', 'o'};
        adj[7] = {'p', 'q', 'r', 's'};
        adj[8] = {'t', 'u', 'v'};
        adj[9] = {'w', 'x', 'y', 'z'};

        vector<string> res;

        struct Frame
        {
            int idx;
            string comb;
        };

        stack<Frame> stk;


        stk.push({0, ""});

        while (!stk.empty())
        {
            auto curr = stk.top();
            stk.pop();
            if (curr.idx == digits.size())
            {
                res.push_back(curr.comb);

                continue;
            }

            int d = digits[curr.idx] - '0';
            for (auto it = adj[d].rbegin(); it != adj[d].rend(); ++it)
            {
                char ch = *it;
                stk.push({curr.idx + 1, curr.comb + ch});
            }
        }

        return res;
    }
};


// Main function provided by user - unchanged.
int main()
{
    Solution s;
    string digits = "23";
    vector<string> result = s.letterCombinations(digits);
    vector<string> expected = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};

    cout << "Test Case 1:" << endl;
    cout << "Input: " << digits << endl;
    cout << "Expected: ";
    for (string str : expected) cout << str << " ";
    cout << endl << "Actual: ";
    for (string str : result) cout << str << " ";
    cout << endl;
    return 0;
}
