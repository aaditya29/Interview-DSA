// leetcode 2536. Increment Submatrices by One
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries)
    {
        vector<vector<int>> diff(n + 1, vector<int>(n + 1, 0));
        for (auto &q : queries)
        {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            diff[r1][c1] += 1;
            diff[r1][c2 + 1] -= 1;
            diff[r2 + 1][c1] -= 1;
            diff[r2 + 1][c2 + 1] += 1;
        }
        vector<vector<int>> result(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result[i][j] = diff[i][j];
                if (i > 0)
                    result[i][j] += result[i - 1][j];
                if (j > 0)
                    result[i][j] += result[i][j - 1];
                if (i > 0 && j > 0)
                    result[i][j] -= result[i - 1][j - 1];
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    int n = 3;
    vector<vector<int>> queries = {{0, 0, 1, 1}, {1, 1, 2, 2}, {0, 0, 2, 2}};
    vector<vector<int>> result = sol.rangeAddQueries(n, queries);
    cout << "Resultant matrix after range add queries:" << endl;
    for (const auto &row : result)
    {
        for (const auto &val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}