#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //find the node with 0 indegree.
        //airports that are in the to spot have indegrees.

        //key is the airport, value is indegree
        unordered_map<string, priority_queue<string, vector<string>, greater<>>> flight_map;


        for (int i = 0; i < tickets.size(); i++)
        {
            flight_map[tickets[i][0]].push(tickets[i][1]);
        }


        stack<string> stk;
        stk.push("JFK");

        vector<string> res;


        while (!stk.empty())
        {
            string curr = stk.top();
            //stk.pop();

            //res.push_back(curr);


            if (flight_map.count(curr) && !flight_map[curr].empty()){

                stk.push(flight_map[curr].top());
                flight_map[curr].pop();

            } else
            {
                stk.pop();
                res.push_back(curr);
            }

        }
        reverse(res.begin(), res.end());
        return res;

    }
};

int main()
{
    Solution s;

    vector<vector<string>> tickets1 = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    vector<vector<string>> tickets2 = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
    vector<vector<string>> tickets3 = {{"JFK", "KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"}};
    vector<vector<string>> tickets4 = {{"BUF", "HOU"}, {"HOU", "SEA"}, {"JFK", "BUF"}};


    cout << "Test case 1: " << endl;
    vector<string> result1 = s.findItinerary(tickets1);
    for (const auto& airport : result1)
    {
        cout << airport << " ";
    }
    cout << endl;

    cout << "Test case 2: " << endl;
    vector<string> result2 = s.findItinerary(tickets2);
    for (const auto& airport : result2)
    {
        cout << airport << " ";
    }
    cout << endl;

    cout << "Test case 3: " << endl;
    vector<string> result3 = s.findItinerary(tickets3);
    for (const auto& airport : result3)
    {
        cout << airport << " ";
    }
    cout << endl;

    cout << "Test case 4: " << endl;
    vector<string> result4 = s.findItinerary(tickets4);
    for (const auto& airport : result4)
    {
        cout << airport << " ";
    }
    cout << endl;

    return 0;
}
