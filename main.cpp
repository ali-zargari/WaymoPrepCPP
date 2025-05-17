#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int visited = 0;
        int limit = matrix.size()*matrix[0].size();

        bool upturn, downturn, leftturn, rightturn;
        upturn = false; downturn = false; leftturn = false; rightturn = true;

        int up, down, left, right;
        up = 0;
        down = matrix.size();
        left = 0;
        right = matrix[0].size();

        pair<int, int> current = {0, 0};

        vector<int> res;


        if (matrix[0].size() == 1) {
            vector<int> out;
            for (auto &row : matrix) out.push_back(row[0]);
            return out;
        }


        while (visited < limit)
        {

            res.push_back(matrix[current.first][current.second]);

            if (current.second < right-1 && rightturn)
            {
                current.second++;

                if (current.second == right-1)
                {
                    right--;
                    rightturn = false;
                    downturn = true;
                }


            }else

            if (current.first < down-1 && downturn)
            {
                current.first++;

                if (current.first == down - 1)
                {
                    down--;
                    downturn = false;
                    leftturn = true;
                }
            } else

            if (current.second > left && leftturn)
            {
                current.second--;

                if (current.second == left)
                {
                    left++;
                    leftturn = false;
                    upturn = true;
                }
            } else

            if (current.first > up && upturn)
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
        for (char task : tasks) {
            um[task]++;
        }

        n++;

        // max-heap for ready tasks: highest count first
        priority_queue<pair<int,char>> ready;
        for (auto &p : um) {
            ready.push({p.second, p.first});
        }
        um.clear();  // no longer needed

        struct Frame {
            int time;
            char letter;
            int count;
        };
        auto cmp = [](const Frame &a, const Frame &b) {
            return a.time > b.time;
        };
        // min-heap by time for cooling tasks
        priority_queue<Frame, vector<Frame>, decltype(cmp)> pq(cmp);

        vector<char> res;
        int index = 0;

        while (!ready.empty() || !pq.empty()) {
            // release any cooled-down task back into ready
            if (!pq.empty() && pq.top().time <= index) {
                Frame cur = pq.top();
                pq.pop();
                if (cur.count > 0) {
                    ready.push({cur.count, cur.letter});
                }
            }

            if (!ready.empty()) {
                // pick the task with largest remaining count
                auto [cnt, ch] = ready.top();
                ready.pop();

                res.push_back(ch);
                cnt--;

                // put it into cooldown
                pq.push({ index + n, ch, cnt });
            }
            else {
                // no task ready => idle
                res.push_back('-');
            }

            index++;
        }




        for (int i = res.size()-1; i >=0; i--)
        {
            if (res[i] == '-')
            {
                res.pop_back();
            } else
            {
                break;
            }
        }

        for (char c:res)
        {
            cout << c << ", ";
        }

        // return total length, trimming trailing idle
        return res.size();
    }

    int search(vector<int>& nums, int target)
    {

        int l = 0;
        int r = nums.size()-1;
        int m = (l+r)/2;

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
                    l = m+1;
                } else // is it on the unsorted side?
                {
                    r = m-1;
                }
            } else // left side is sorted
            {

                if (nums[l] <= target and nums[m] >= target)
                {
                    r = m-1;
                } else
                {
                    l = m+1;
                }
            }
        }

        return -1;
    }
};



int main()
{
    Solution s;
    //
    // // Test case 1: Regular rotated array
    // vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    // cout << "Test 1 (should return 4): " << s.search(nums1, 0) << endl;

    // Test case 2: Target not found
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Test 2 (should return -1): " << s.search(nums2, 3) << endl;

    // Test case 3: Single element array
    vector<int> nums3 = {1};
    cout << "Test 3 (should return 0): " << s.search(nums3, 1) << endl;

    // Test case 4: Empty array
    vector<int> nums4 = {};
    cout << "Test 4 (should return -1): " << s.search(nums4, 5) << endl;

    return 0;
}
