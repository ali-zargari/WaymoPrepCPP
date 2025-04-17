#include <iostream>
#include <vector>
#include <map>
#include <queue>


using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {

        priority_queue<pair<int, int>> pq;
        pair<int, int> p;
        map<int, int> s;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++)
        {
            s[nums[i]]++;
        }

        for (auto [key, value]: s)
        {
            cout << "(" << key << ", " << value << ") " << endl;
            p = make_pair(value, key);
            pq.push(p);
        }

        for (int i = 0; i < k; i++)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};

int main()
{

    vector<int> in = {1, 1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5};
    int k = 3;

    Solution s;
    vector<int> result = s.topKFrequent(in, k);

    for (const auto i: result)
    {
        cout << i << "-";
    }

    return 0;
}

