#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>

#include <vector>


using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //We can go through the tasks. We process the first one. We keep going through the list. If the next is equal,
        //we remove it (maybe add it to a waiting queue). Then continue, and check waiting queue. If one is ready,
        //then we pop from queue, and process.


        vector<int> count(26, 0);

        for (const char i: tasks)
        {
            count[i-'A']++;
        }

        priority_queue<int> task_list;
        for (int i : count)
        {
            if (i != 0)
            {
                task_list.push(i);
            }
        }

        int time = 0;
        queue<pair<int, int>> waiting;

        while (!waiting.empty() || !task_list.empty())
        {

            if (!waiting.empty() && waiting.front().second <= time)
            {
                task_list.push(waiting.front().first);
                waiting.pop();
            }

            if (!task_list.empty())
            {
                int temp = task_list.top();
                task_list.pop();
                if (temp - 1 > 0)
                {
                    waiting.emplace(temp - 1, time + n + 1);
                }

            } else
            {
                time = waiting.front().second;
            }


            time++;
        }

        return time;
    }

};


// Main function provided by user - unchanged.
int main()
{


    Solution s;

    //s.leastInterval({'A', 'A', 'A', 'B', 'C', 'B'}, 2);


    vector<char> tasks1 = {'A', 'A', 'A', 'B', 'C', 'B'};
    int n1 = 2;
    cout << "Test Case 1: " << s.leastInterval(tasks1, n1) << endl;

    vector<char> tasks2 = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n2 = 0;
    cout << "Test Case 2: " << s.leastInterval(tasks2, n2) << endl;

    vector<char> tasks3 = {'A', 'B', 'C', 'A', 'B', 'A'};
    int n3 = 2;
    cout << "Test Case 3: " << s.leastInterval(tasks3, n3) << endl;

    vector<char> tasks4 = {'A'};
    int n4 = 2;
    cout << "Test Case 4: " << s.leastInterval(tasks4, n4) << endl;

    vector<char> tasks5 = {'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D'};
    int n5 = 3;
    cout << "Test Case 5: " << s.leastInterval(tasks5, n5) << endl;

    //["A","A","A","B","C","B"], 2

    // A -> B -> C -> A -> B -> -> A

    return 0;
}
