#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class TimeMap
{
public:
    unordered_map<string, map<int, string>> um;
    int mostRecent;

    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        um[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        auto it = um[key].upper_bound(timestamp);
        return it == um[key].begin() ? "" : prev(it)->second;
    }
};


int main()
{
    TimeMap timeMap;
    timeMap.set("alice", "happy", 1); // store the key "alice" and value "happy" along with timestamp = 1.
    cout << timeMap.get("alice", 1) << endl; // return "happy"
    cout << timeMap.get("alice", 2) << endl;
    // return "happy", there is no value stored for timestamp 2, thus we return the value at timestamp 1.
    timeMap.set("alice", "sad", 3); // store the key "alice" and value "sad" along with timestamp = 3.
    cout << timeMap.get("alice", 3) << endl; // return "sad"

    return 0;
}
