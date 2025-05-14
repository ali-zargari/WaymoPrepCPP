#include <queue>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        //start from k, and do a BFS. we will save all the accumulated delay times.

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.emplace(0, k);

        unordered_map<int, vector<pair<int, int>>> graph;
        unordered_set<int> visited;
        int time = 1;

        for (auto& stats : times)
        {
            // stats[0] = source, stats[1] = destination, stats[2] = time
            graph[stats[0]].emplace_back(stats[1], stats[2]);
        }

        // Initialize distances to all vertices as infinity
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        while (!q.empty())
        {
            auto current = q.top();
            q.pop();
            int currTime = current.first;
            int currNode = current.second;

            if (visited.count(currNode))
            {
                continue;
            }

            visited.insert(currNode);


            for (auto& dest : graph[currNode]) {
                int next = dest.first;
                int weight = dest.second;
                if (!visited.count(next) && currTime + weight < dist[next]) {
                    dist[next] = currTime + weight;
                    q.emplace(dist[next], next);
                    }
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX)
                return -1;                  // some node never reached
            time = max(time, dist[i]);      // longest shortest path
        }
        return time;
    }
};


int main()
{
    Solution s;

    vector<vector<int>> times = {{1, 2, 1}, {2, 3, 1}, {1, 4, 4}, {3, 4, 1}};
    int n = 4, k = 1;
    cout << s.networkDelayTime(times, n, k) << endl; // Should output: 2

    times = {{1, 2, 1}, {2, 3, 1}};
    n = 3, k = 2;
    cout << s.networkDelayTime(times, n, k) << endl; // Should output: 1

    times = {{1, 2, 1}};
    n = 2, k = 2;
    cout << s.networkDelayTime(times, n, k) << endl; // Should output: -1
    return 0;
}
