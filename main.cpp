#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <unordered_map>

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
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int visited = 0;
        int limit = matrix.size() * matrix[0].size();

        bool upturn, downturn, leftturn, rightturn;
        upturn = false;
        downturn = false;
        leftturn = false;
        rightturn = true;

        int up, down, left, right;
        up = 0;
        down = matrix.size();
        left = 0;
        right = matrix[0].size();

        pair<int, int> current = {0, 0};

        vector<int> res;


        if (matrix[0].size() == 1)
        {
            vector<int> out;
            for (auto& row : matrix) out.push_back(row[0]);
            return out;
        }


        while (visited < limit)
        {
            res.push_back(matrix[current.first][current.second]);

            if (current.second < right - 1 && rightturn)
            {
                current.second++;

                if (current.second == right - 1)
                {
                    right--;
                    rightturn = false;
                    downturn = true;
                }
            }
            else if (current.first < down - 1 && downturn)
            {
                current.first++;

                if (current.first == down - 1)
                {
                    down--;
                    downturn = false;
                    leftturn = true;
                }
            }
            else if (current.second > left && leftturn)
            {
                current.second--;

                if (current.second == left)
                {
                    left++;
                    leftturn = false;
                    upturn = true;
                }
            }
            else if (current.first > up && upturn)
            {
                current.first--;

                if (current.first == up + 1)
                {
                    up++;
                    upturn = false;
                    rightturn = true;
                }
            }


            visited++;
        }
        return res;
    }


    int leastInterval(vector<char>& tasks, int n)
    {
        // count frequencies
        unordered_map<char, int> um;
        for (char task : tasks)
        {
            um[task]++;
        }

        n++;

        // max-heap for ready tasks: highest count first
        priority_queue<pair<int, char>> ready;
        for (auto& p : um)
        {
            ready.push({p.second, p.first});
        }
        um.clear(); // no longer needed

        struct Frame
        {
            int time;
            char letter;
            int count;
        };
        auto cmp = [](const Frame& a, const Frame& b)
        {
            return a.time > b.time;
        };
        // min-heap by time for cooling tasks
        priority_queue<Frame, vector<Frame>, decltype(cmp)> pq(cmp);

        vector<char> res;
        int index = 0;

        while (!ready.empty() || !pq.empty())
        {
            // release any cooled-down task back into ready
            if (!pq.empty() && pq.top().time <= index)
            {
                Frame cur = pq.top();
                pq.pop();
                if (cur.count > 0)
                {
                    ready.push({cur.count, cur.letter});
                }
            }

            if (!ready.empty())
            {
                // pick the task with largest remaining count
                auto [cnt, ch] = ready.top();
                ready.pop();

                res.push_back(ch);
                cnt--;

                // put it into cooldown
                pq.push({index + n, ch, cnt});
            }
            else
            {
                // no task ready => idle
                res.push_back('-');
            }

            index++;
        }


        for (int i = res.size() - 1; i >= 0; i--)
        {
            if (res[i] == '-')
            {
                res.pop_back();
            }
            else
            {
                break;
            }
        }

        for (char c : res)
        {
            cout << c << ", ";
        }

        // return total length, trimming trailing idle
        return res.size();
    }

    int search(vector<int>& nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int m = (l + r) / 2;

        while (l <= r)
        {
            if (nums[m] == target)
            {
                return m;
            }

            //right side is sorted
            if (nums[l] > nums[m])
            {
                // is it in sorted side?
                if (nums[m] <= target and nums[r] >= target)
                {
                    l = m + 1;
                }
                else // is it on the unsorted side?
                {
                    r = m - 1;
                }
            }
            else // left side is sorted
            {
                if (nums[l] <= target and nums[m] >= target)
                {
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
        }

        return -1;
    }


    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (!q and !p)
        {
            return true;
        }

        if (q->val != p->val)
        {
            return false;
        }


        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }

    bool isSubTree(TreeNode* tree, TreeNode* subtree)
    {

        if (!tree)
        {
            return false;
        }
        
        if (tree->val == subtree->val)
        {
            return isSameTree(tree, subtree);
        }
        

        return isSubTree(tree->left, subtree) or isSameTree(tree->right, subtree);
    }


    TreeNode* createTree(vector<int> nums)
    {
        if (nums.empty()) return nullptr;

        TreeNode* node = new TreeNode(nums[0]);

        queue<TreeNode*> q;

        q.push(node);

        int index = 1;

        while (!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();

            if (index < nums.size())
            {
                curr->left = new TreeNode(nums[index]);
                q.push(curr->left);
                index++;
            }

            if (index < nums.size())
            {
                curr->right = new TreeNode(nums[index]);
                q.push(curr->right);
                index++;
            }
        }

        return node;
    }


    vector<vector<int>> levelOrder(TreeNode* root)
    {

        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;

        while (!q.empty())
        {
            //TreeNode* curr = q.front();

            int n = q.size();
            vector<int> subres;

            for (int i = 0; i < n; i++)
            {
                TreeNode* curr = q.front();
                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
                subres.push_back(curr->val);
                q.pop();
            }

            //q.pop();
            res.push_back(subres);
        }

        return res;
    }


    vector<set<int>> threesumRes;

    void t3dfs(vector<int> nums, set<int> seen, int index, int currSum, int k, int sum)
    {
        if (index >= nums.size())
        {
            return;
        }

        if (seen.count(index))
        {
            return;
        }

        if (seen.size() == k)
        {
            if (currSum == sum)
            {
                threesumRes.push_back(seen);
            }
            return;
        }

        t3dfs(nums, seen, index+1, currSum, k, sum);

        int newSum = currSum + nums[index];
        seen.insert(index);

        t3dfs(nums, seen, index+1, newSum, k, sum);

    }

    vector<vector<int>> threeSum(vector<int>& nums, int k) {
        t3dfs(nums, {}, 0, 0, k, 0);


        vector<vector<int>> result;
        for (const auto& set : threesumRes)
        {
            result.push_back(vector<int>(set.begin(), set.end()));
        }
        return result;
    }





};


int main()
{
    Solution s;

    // Test binary tree creation
    vector<int> treeValues = {1, 2, 3, 4, -1, 6, 7};
    TreeNode* root = s.createTree(treeValues);

    // Verify tree structure
    if (root)
    {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                cout << curr->val << " ";

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            cout << endl;
        }
    }


    // Test isSameTree function
    vector<int> tree1Values = {1, 2, 3, 4, 5, 6, 7};
    vector<int> tree2Values = {1, 2, 3, 4, 5, 6, 7};
    vector<int> tree3Values = {1, 2, 3, 4, 5, 8, 7};

    TreeNode* tree1 = s.createTree(tree1Values);
    TreeNode* tree2 = s.createTree(tree2Values);
    TreeNode* tree3 = s.createTree(tree3Values);

    cout << "\nTesting isSameTree function:" << endl;
    cout << "Identical trees comparison result: " << boolalpha << s.isSameTree(tree1, tree2) << endl;
    cout << "Different trees comparison result: " << boolalpha << s.isSameTree(tree1, tree3) << endl;

    // Test isSubTree function
    vector<int> mainTreeValues = {3, 4, 5, 1, 2, -1, -1};
    vector<int> subTreeValues = {4, 1, 2};
    TreeNode* mainTree = s.createTree(mainTreeValues);
    TreeNode* subTree = s.createTree(subTreeValues);

    cout << "\nTesting isSubTree function:" << endl;
    cout << "Is subTree present: " << boolalpha << s.isSubTree(mainTree, subTree) << endl;
// Test levelOrder function - traverses tree level by level
    cout << "\nTesting levelOrder function:" << endl;
    cout << "Input tree: [1,2,3,4,5,6,7]" << endl;
    cout << "Expected output:" << endl;
    cout << "1" << endl;
    cout << "2 3" << endl;
    cout << "4 5 6 7" << endl;
    cout << "\nActual output:" << endl;
    vector<vector<int>> levels = s.levelOrder(tree1);
    for (const auto& level : levels)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }


    // Test threeSum function
    cout << "\nTesting threeSum function:" << endl;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int k = 3;
    cout << "Input array: ";
    for (int num : nums) cout << num << " ";
    cout << "\nk = " << k << endl;

    cout << "Output combinations:" << endl;
    vector<vector<int>> combinations = s.threeSum(nums, k);
    for (const auto& combo : combinations)
    {
        for (int num : combo)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
