#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <iostream>


using namespace std;

class HitCounter
{
public:

    vector<pair<int, int>> timeline;
    int count;

    HitCounter()
    {
        count = 0;
        //first = timestamp
        // second = count
        timeline = vector<pair<int, int>>(300, {0, 0});
    }

    void hit(int timeStamp)
    {
        int index = timeStamp % 300;

        if (timeline[index].first == timeStamp)
        {
            timeline[index].second++;
        } else
        {
            timeline[index].first = timeStamp;
            timeline[index].second = 1;
        }

    }

    int getHits(int timeStamp)
    {
        int total = 0;

        for (int i = 0; i < 300; i++)
        {
            pair<int, int> bucket = timeline[i];

            if (timeStamp - bucket.first < 300)
            {
                total += bucket.second;
            }
        }

        return total;
    }


};

// hit(1) adds hit to timestamp 1
// hit(2) adds hit to timestamp 2
// hit(3) adds hit to timestamp 3
// 1-2-3 ... 304
// get hit(4) 3-300 = -297...1 2 3

// --- Main function with test cases (modified slightly for clarity) ---
int main()
{
    HitCounter counter;

// hit at timestamp 1.
    counter.hit(1);

    // hit at timestamp 2.
    counter.hit(2);

    // hit at timestamp 3.
    counter.hit(3);

    // get hits at timestamp 4, should return 3.
    cout << counter.getHits(4) << endl;

    // hit at timestamp 300.
    counter.hit(300);

    counter.hit(600);

    // get hits at timestamp 300, should return 4.
    cout << counter.getHits(300) << endl;

    // get hits at timestamp 301, should return 3.
    cout << counter.getHits(900) << endl;
    return 0;
}
