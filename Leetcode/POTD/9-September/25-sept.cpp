// Leetcode 120. Triangle
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> dp(triangle[n - 1]);
        for (int row = n - 2; row >= 0; row--)
        {
            for (int col = 0; col <= row; col++)
            {
                dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
            }
        }
        return dp[0];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << sol.minimumTotal(triangle) << endl; // Output: 11
    return 0;
}