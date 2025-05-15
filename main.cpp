#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int visited = 0;
        int limit = matrix.size()*matrix[0].size();

        bool upturn, downturn, leftturn, rightturn;
        upturn = false; downturn = false; leftturn = false; rightturn = true;

        int up, down, left, right;
        up = 0;
        down = matrix.size();
        left = 0;
        right = matrix[0].size();

        pair<int, int> current = {0, 0};

        vector<int> res;


        if (matrix[0].size() == 1) {
            vector<int> out;
            for (auto &row : matrix) out.push_back(row[0]);
            return out;
        }


        while (visited < limit)
        {

            res.push_back(matrix[current.first][current.second]);

            if (current.second < right-1 && rightturn)
            {
                current.second++;

                if (current.second == right-1)
                {
                    right--;
                    rightturn = false;
                    downturn = true;
                }


            }else

            if (current.first < down-1 && downturn)
            {
                current.first++;

                if (current.first == down - 1)
                {
                    down--;
                    downturn = false;
                    leftturn = true;
                }
            } else

            if (current.second > left && leftturn)
            {
                current.second--;

                if (current.second == left)
                {
                    left++;
                    leftturn = false;
                    upturn = true;
                }
            } else

            if (current.first > up && upturn)
            {
                current.first--;

                if (current.first == up + 1)
                {
                    up++;
                    upturn = false;
                    rightturn = true;
                }
            }


            visited++;
        }
        return res;
    }
};



int main()
{
    Solution s;

    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> matrix2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    cout << "Test case 1:" << endl;
    vector<int> result1 = s.spiralOrder(matrix1);
    cout << "Expected: [1,2,3,6,9,8,7,4,5]" << endl;
    cout << "Got: [";
    for (int i = 0; i < result1.size(); i++)
    {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    cout << "\nTest case 2:" << endl;
    vector<int> result2 = s.spiralOrder(matrix2);
    cout << "Expected: [1,2,3,4,8,12,11,10,9,5,6,7]" << endl;
    cout << "Got: [";
    for (int i = 0; i < result2.size(); i++)
    {
        cout << result2[i];
        if (i < result2.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
