// leetcode 2435. Paths in Matrix Whose Sum is Divisible by K
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    const int mod = 1e9 + 7;
    int solve(int i, int j, int sum, vector<vector<int>> &grid, int k,
              vector<vector<vector<int>>> &dp)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (i == n - 1 && j == m - 1)
        {
            sum = (sum + grid[i][j]) % k;
            if (sum == 0)
            {
                return 1;
            }

            return 0;
        }
        if (i == n || j == m)
        {
            return 0;
        }

        if (dp[i][j][sum] != -1)
        {
            return dp[i][j][sum];
        }

        int right = solve(i, j + 1, (sum + grid[i][j]) % k, grid, k, dp);
        int down = solve(i + 1, j, (sum + grid[i][j]) % k, grid, k, dp);

        return dp[i][j][sum] = (right + down) % mod;
    }
    int numberOfPaths(vector<vector<int>> &grid, int k)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
        return solve(0, 0, 0, grid, k, dp);
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // Example input
    int k = 3;                                                    // Example divisor
    int result = sol.numberOfPaths(grid, k);
    cout << "Number of paths with sum divisible by " << k << ": " << result << endl;
    return 0;
}
