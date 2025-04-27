#include <cmath>
#include <iostream>
#include <queue>
#include <vector>


using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // we want the k closest point to origin. We can keep the distances in a max heap.
        // Then we just return the kth smallest.


        priority_queue<pair<float, int>> dist_heap;
        vector<vector<int>> res;

        int i = 0;
        for (vector <int> point: points)
        {
            int x = point[0];
            int y = point[1];

            auto dist = static_cast<float>(sqrt((x * x) + (y * y)));

            dist_heap.emplace(dist, i);
            i++;

            if (dist_heap.size() > k)
            {
                dist_heap.pop();
            }
        }


        while(!dist_heap.empty())
        {
            res.emplace_back(vector<int>(points[dist_heap.top().second]));
            dist_heap.pop();
        }


        return res;

    }
};




// Main function provided by user - unchanged.
int main()
{
    Solution sol;
    // Test case #1
    vector<vector<int>> points1 = {{1, 3}, {-2, 2}};
    int k1 = 1;
    vector<vector<int>> result1 = sol.kClosest(points1, k1);
    cout << "Test case #1 - Expected: [[-2,2]], Actual: ";
    for (auto& point : result1)
    {
        cout << "[" << point[0] << "," << point[1] << "] ";
    }
    cout << endl;

    // Test case #2
    vector<vector<int>> points2 = {{3, 3}, {5, -1}, {-2, 4}};
    int k2 = 2;
    vector<vector<int>> result2 = sol.kClosest(points2, k2);
    cout << "Test case #2 - Expected: [[3,3],[-2,4]], Actual: ";
    for (auto& point : result2)
    {
        cout << "[" << point[0] << "," << point[1] << "] ";
    }
    cout << endl;

    // Test case #3
    vector<vector<int>> points3 = {{0, 1}, {1, 0}, {0, 2}, {2, 0}, {-1, -1}};
    int k3 = 3;
    vector<vector<int>> result3 = sol.kClosest(points3, k3);
    cout << "Test case #3 - Expected: [[0,1],[1,0],[-1,-1]], Actual: ";
    for (auto& point : result3)
    {
        cout << "[" << point[0] << "," << point[1] << "] ";
    }
    cout << endl;

    // Test case #4: No points
    vector<vector<int>> points4 = {};
    int k4 = 1;
    vector<vector<int>> result4 = sol.kClosest(points4, k4);
    cout << "Test case #4 - Expected: [], Actual: ";
    for (auto& point : result4)
    {
        cout << "[" << point[0] << "," << point[1] << "] ";
    }
    cout << endl;

    // Test case #5: All points returned
    vector<vector<int>> points5 = {{2, 2}, {3, 3}};
    int k5 = 2;
    vector<vector<int>> result5 = sol.kClosest(points5, k5);
    cout << "Test case #5 - Expected: [[2,2],[3,3]], Actual: ";
    for (auto& point : result5)
    {
        cout << "[" << point[0] << "," << point[1] << "] ";
    }
    cout << endl;

    return 0;
}
