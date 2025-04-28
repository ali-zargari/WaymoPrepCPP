#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //

        vector<int> freq(26, 0);

        for(char task:tasks){
            freq[task-'A']++;
        }

        priority_queue<int> pq;

        for(int i : freq){
            if(i != 0){
                pq.push(i);
            }
        }

        // count, cooldown
        queue<pair<int, int>> waiting;

        int time = 0;


        while(!waiting.empty() || !pq.empty()){


            if(!waiting.empty() && waiting.front().second == time){
                auto temp = waiting.front();
                waiting.pop();

                if(temp.first != 0)
                    pq.emplace(temp.first);
            }

            if(!pq.empty()){
                auto temp = pq.top();
                pq.pop();
                if(temp-1 > 0)
                    waiting.emplace(temp-1, time+n+1);
            }


            if(waiting.front().first == 0){
                waiting.pop();
                if(pq.empty() && waiting.empty()){
                    return time;
                }
            }

            time++;
        }

        return time;
    }

};



// To execute C++, please define "int main()"
int main() {


    //A, A, A, B, C, B
    Solution s;

    vector<char> v = {'X', 'X', 'Y', 'Y'};
    vector<char> v2 = {'A', 'A', 'A', 'B', 'C'};

    //A, A, A, B, C, B ; n=2
    //A-B-C-A-B-Idle-A

    //A, A, A, B, C ; n=3
    //A-B-C-Idle-A-Idle-Idle-Idle-A

    //3, 1, 1

    cout << s.leastInterval(v, 2) << endl;
    cout << s.leastInterval(v2, 3) << endl;

    return 0;
}
