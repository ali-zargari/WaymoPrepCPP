#include <iomanip> // Needed for setprecision
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility> // Needed for std::pair
#include <vector>  // Needed for printStack helper

using namespace std;

// Helper function to print stack contents cleanly (shows bottom to top)
void printStack(stack<double> s) { // Pass by value to get a copy
    if (s.empty()) {
        cout << "{empty}" << endl;
        return;
    }
    cout << "{ ";
    vector<double> temp; // Use a vector to reverse easily for printing bottom-up
    while(!s.empty()){
        temp.push_back(s.top());
        s.pop();
    }
    reverse(temp.begin(), temp.end()); // Show bottom elements first
    cout << fixed << setprecision(2); // Format time output consistently
    for(size_t i=0; i<temp.size(); ++i){
        // Print element, add comma unless it's the last one
        cout << temp[i] << (i == temp.size() - 1 ? "" : ", ");
    }
    // Indicate which end is the top
    cout << " } (Top is rightmost)" << endl;
}

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        cout << "\n--- Starting carFleet calculation ---" << endl;
        cout << "Target: " << target << endl;
        cout << "Input Positions: "; for(int p : position) cout << p << " "; cout << endl;
        cout << "Input Speeds:    "; for(int s : speed) cout << s << " "; cout << endl;

        if (n == 0) {
            cout << "Input is empty, returning 0 fleets." << endl;
            cout << "--- Calculation End ---" << endl;
            return 0;
        }

        // Create pairs of {position, time_to_target}
        vector<pair<int, double>> cars(n); // Use double for precision
        cout << "\nCalculating arrival times:" << endl;
        for (int i = 0; i < n; i++) {
            // Ensure floating point division
            double time_to_target = static_cast<double>(target - position[i]) / speed[i];
            cars[i] = {position[i], time_to_target};
             cout << "  Car at pos " << setw(3) << position[i] << " (spd " << setw(2) << speed[i] << ") takes "
                  << fixed << setprecision(2) << time_to_target << " time." << endl;
        }

        // Sort cars based on starting position in DESCENDING order
        // Cars furthest from target (largest position) appear first in the vector
        sort(cars.rbegin(), cars.rend());
        cout << "\nCars sorted by position (descending - furthest first):" << endl;
        cout << fixed << setprecision(2); // Ensure precision for printing
        for(int i=0; i<n; ++i) {
            cout << "  Index " << i << ": {Pos: " << setw(3) << cars[i].first
                 << ", Time: " << cars[i].second << "}" << endl;
        }

        stack<double> fleets; // Stores arrival times of fleet leaders
        cout << "\n--- Processing cars (Furthest Position to Closest Position) ---" << endl;

        // Iterate through sorted cars (index 0 is furthest car)
        for (int i = 0; i < n; i++) {
            double currentTime = cars[i].second;
            cout << "\nProcessing Car Index " << i << ": {Pos: " << cars[i].first << ", Time: " << currentTime << "}" << endl;
            cout << "  Stack before check: "; printStack(fleets);

            // Logic: If stack is empty OR this car arrives LATER than the fleet leader
            // identified from the cars processed so far (which are further away),
            // then this car forms a NEW fleet leader.
            if (fleets.empty()) {
                 cout << "  Stack is empty. This car (furthest processed so far) forms the first fleet leader." << endl;
                 cout << "  Pushing its time " << currentTime << " onto stack." << endl;
                 fleets.push(currentTime);
            } else {
                 cout << "  Comparing currentTime (" << currentTime << ") with stack top (" << fleets.top() << ")." << endl;
                 if (currentTime > fleets.top()) {
                     // This car arrives later than the leader of the fleet(s) formed by cars 0..i-1
                     cout << "  Result: currentTime > stack top. This car cannot catch the fleet(s) ahead." << endl;
                     cout << "  It forms a new fleet. Pushing its time " << currentTime << " onto stack." << endl;
                     fleets.push(currentTime);
                 } else {
                     // This car arrives at the same time or earlier than the fleet leader ahead.
                     cout << "  Result: currentTime <= stack top. This car will merge with the fleet ahead." << endl;
                     cout << "  Doing nothing to the stack (it doesn't form a new fleet)." << endl;
                 }
            }
            cout << "  Stack after check:  "; printStack(fleets);
        }

        cout << "\n--- Processing Complete ---" << endl;
        cout << "Final stack state: "; printStack(fleets);
        int finalFleetCount = fleets.size();
        cout << "Final number of fleets (stack size): " << finalFleetCount << endl;
        cout << "--- Calculation End ---" << endl;
        return finalFleetCount;
    }
};



int main()
{
    Solution s;

    // Example from this prompt
    vector<int> pos1 = {10, 8, 0, 5, 3};
    vector<int> spd1 = {1, 4, 15, 1, 3};
    int target1 = 15;
    int expected1 = 2; // Expected for this example
    cout << "=============================" << endl;
    cout << "        Test Case 1"          << endl;
    cout << "=============================" << endl;
    int actual1 = s.carFleet(target1, pos1, spd1);
    cout << "\nMain function check -> Actual: " << actual1 << ", Expected: " << expected1 << endl;
    cout << "=============================" << endl;


    // Original example from previous prompts
    vector<int> pos2 = {10, 8, 0, 5, 3};
    vector<int> spd2 = {2, 4, 1, 1, 3};
    int target2 = 12;
    int expected2 = 3; // Expected for this example
    cout << "\n=============================" << endl;
    cout << "        Test Case 2"          << endl;
    cout << "=============================" << endl;
    int actual2 = s.carFleet(target2, pos2, spd2);
    cout << "\nMain function check -> Actual: " << actual2 << ", Expected: " << expected2 << endl;
    cout << "=============================" << endl;

    return 0;
}