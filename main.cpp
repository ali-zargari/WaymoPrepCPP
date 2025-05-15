#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), -1));

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j< matrix[i].size(); j++)
            {
                int newCol = matrix[i].size() - i - 1;
                res[j][newCol] = matrix[i][j];
            }
        }

        matrix = res;
    }
};


int main()
{
    Solution s;

// Test case 1: 3x3 matrix
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<vector<int>> expected1 = {
        {7, 4, 1},
        {8, 5, 2},
        {9, 6, 3}
    };
    s.rotate(matrix1);
    cout << "Test case 1:\nExpected:\n";
    for (const auto& row : expected1)
    {
        for (const auto& val : row) cout << val << " ";
        cout << "\n";
    }
    cout << "Actual:\n";
    for (const auto& row : matrix1)
    {
        for (const auto& val : row) cout << val << " ";
        cout << "\n";
    }

    // Test case 2: 4x4 matrix
    vector<vector<int>> matrix2 = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };
    vector<vector<int>> expected2 = {
        {15, 13, 2, 5},
        {14, 3, 4, 1},
        {12, 6, 8, 9},
        {16, 7, 10, 11}
    };
    s.rotate(matrix2);
    cout << "\nTest case 2:\nExpected:\n";
    for (const auto& row : expected2)
    {
        for (const auto& val : row) cout << val << " ";
        cout << "\n";
    }
    cout << "Actual:\n";
    for (const auto& row : matrix2)
    {
        for (const auto& val : row) cout << val << " ";
        cout << "\n";
    }

    // Test case 3: Empty matrix
    vector<vector<int>> matrix3;
    s.rotate(matrix3);
    cout << "\nTest case 3:\nEmpty matrix - no output expected\n";

    // Test case 4: 1x1 matrix
    vector<vector<int>> matrix4 = {{1}};
    vector<vector<int>> expected4 = {{1}};
    s.rotate(matrix4);
    cout << "\nTest case 4:\nExpected:\n";
    for (const auto& row : expected4)
    {
        for (const auto& val : row) cout << val << " ";
        cout << "\n";
    }
    cout << "Actual:\n";
    for (const auto& row : matrix4)
    {
        for (const auto& val : row) cout << val << " ";
        cout << "\n";
    }
    return 0;
}
