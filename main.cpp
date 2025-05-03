#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <iostream>


using namespace std;

class HitCounter
{
public:

    // first timestamp, second count
    deque<pair<int, int>> timeline;



    HitCounter()
    {
        //timeline.reserve(300);
        count = 0;
    }

    void hit(int timeStamp)
    {

        if (!timeline.empty() && timeline.back().first == timeStamp)
        {
            timeline.back().second++;
        } else
        {
            timeline.emplace_back(timeStamp, 1);
        }
        count++;

    }

    int getHits(int timeStamp)
    {

        while (!timeline.empty() && timeStamp - 300 >= timeline.front().first)
        {
            count -= timeline.front().second;
            timeline.pop_front();
        }
        return count;
    }

private:
    int count;




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

    // get hits at timestamp 300, should return 4.
    cout << counter.getHits(300) << endl;

    // get hits at timestamp 301, should return 3.
    cout << counter.getHits(301) << endl;
    return 0;
}
