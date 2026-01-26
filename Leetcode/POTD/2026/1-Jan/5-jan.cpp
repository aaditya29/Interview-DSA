// leetcode 1975. Maximum Matrix Sum
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long long sum = 0;
        int n = matrix.size();
        int count = 0;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum += abs(matrix[i][j]);
                if (matrix[i][j] < 0)
                    count++;
                mini = min(mini, abs(matrix[i][j]));
            }
        }
        if (count % 2 == 0)
            return sum;
        else
            return sum - 2 * mini;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{1, -1, 0}, {-1, -1, -1}, {0, -1, 1}};
    cout << sol.maxMatrixSum(matrix) << endl; // Output: 8
    return 0;
}