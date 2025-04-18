#include <iomanip>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>


using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //We can simulate each "tick" using a forloop.
        //If a car is overtaking another car, we set the speed of the faster one to the one it is overtaking.
        //Every time a car pos gets to the target, we add one to the fleet.
        //but this isnt optimal.

        //We can calculate the time it takes for each car to get to the target mathematically.
        //We add these times to a monotonically increasing stack. the length of this stack is going to be the number of fleets.


        vector<pair<int, float>> cars;

        for (int i = 0; i < position.size(); i++)
        {
            cars.push_back({position[i], (float)(target-position[i])/(float)speed[i]});

        }

        sort(cars.rbegin(), cars.rend());

        stack<double> fleet_times; // Stack to store arrival times of fleet leaders


        for (int i = 0; i < position.size(); ++i) {
            double current_time = cars[i].second;

            if (fleet_times.empty() || current_time > fleet_times.top()) {
                fleet_times.push(current_time);
            }
        }

        return fleet_times.size();

    }
};



int main()
{

    Solution s;

    vector<int> pos = {10,8,0,5,3};
    vector<int> spd = {2,4,1,1,3};
    int target = 12;

    cout << s.carFleet(target, pos, spd) << endl;

    return 0;
}

