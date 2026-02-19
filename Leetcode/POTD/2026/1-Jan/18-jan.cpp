// leetcode 1895. Largest Magic Square
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int largestMagicSquare(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> rowSum(m, vector<int>(n + 1));
        vector<vector<int>> colSum(m + 1, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
                colSum[i + 1][j] = colSum[i][j] + grid[i][j];
            }
        }

        for (int k = min(m, n); k > 0; k--)
        {
            for (int i = 0; i <= m - k; i++)
            {
                for (int j = 0; j <= n - k; j++)
                {
                    int target = rowSum[i][j + k] - rowSum[i][j];

                    bool valid = true;
                    for (int r = i; r < i + k && valid; r++)
                    {
                        if (rowSum[r][j + k] - rowSum[r][j] != target)
                            valid = false;
                    }

                    for (int c = j; c < j + k && valid; c++)
                    {
                        if (colSum[i + k][c] - colSum[i][c] != target)
                            valid = false;
                    }

                    int d1 = 0, d2 = 0;
                    for (int x = 0; x < k && valid; x++)
                    {
                        d1 += grid[i + x][j + x];
                        d2 += grid[i + x][j + k - 1 - x];
                    }

                    if (valid && d1 == target && d2 == target)
                    {
                        return k;
                    }
                }
            }
        }

        return 1;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{7, 1, 4, 5, 6},
                                {2, 5, 1, 6, 4},
                                {1, 5, 4, 3, 2},
                                {1, 2, 7, 3, 4}};
    int result = sol.largestMagicSquare(grid);
    return 0;
}