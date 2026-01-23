// leetcode 1351. Count Negative Numbers in a Sorted Matrix
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int total = n + m;
        int result = 0;
        int current = 0;
        for (int i = 0; i < n; i++)
        {
            while (current < m && grid[i][m - current - 1] < 0)
            {
                current++;
            }
            result += current;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3}};
    int result = sol.countNegatives(grid);
    cout << "Count of negative numbers: " << result << endl;
    return 0;
}