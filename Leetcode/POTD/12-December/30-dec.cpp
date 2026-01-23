#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 2; i < row; i++)
        {
            vector<int> a, b, c;
            a = grid[i - 2];
            b = grid[i - 1];
            c = grid[i];
            unordered_map<int, bool> m;
            int j = 0;
            while (j + 2 < col)
            {
                unordered_map<int, bool> m;
                bool flag = 1;
                for (int k = j; k <= j + 2; k++)
                {
                    if (a[k] > 9 || a[k] < 1 || m.count(a[k]) == 1)
                    {
                        flag = 0;
                        break;
                    }
                    m[a[k]] = 1;
                    if (b[k] > 9 || b[k] < 1 || m.count(b[k]) == 1)
                    {
                        flag = 0;
                        break;
                    }
                    m[b[k]] = 1;
                    if (c[k] > 9 || c[k] < 1 || m.count(c[k]) == 1)
                    {
                        flag = 0;
                        break;
                    }
                    m[c[k]] = 1;
                }
                if (flag == 1)
                {

                    int sum1 = a[j] + b[j + 1] + c[j + 2];
                    int sum2 = a[j + 2] + b[j + 1] + c[j];
                    int cols1 = a[j] + b[j] + c[j];
                    int cols2 = a[j + 1] + b[j + 1] + c[j + 1];
                    int cols3 = a[j + 2] + b[j + 2] + c[j + 2];
                    int rows1 = a[j] + a[j + 1] + a[j + 2];
                    int rows2 = b[j] + b[j + 1] + b[j + 2];
                    int rows3 = c[j] + c[j + 1] + c[j + 2];
                    if (sum1 == sum2 && (cols1 == cols2 && cols2 == cols3 && cols3 == cols1) && (rows1 == rows2 && rows2 == rows3 && rows3 == rows1))
                        ans++;
                }
                j++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {
        {4, 3, 8, 4},
        {9, 5, 1, 9},
        {2, 7, 6, 2}};
    int result = sol.numMagicSquaresInside(grid);
    cout << "Number of magic squares: " << result << endl;
    return 0;
}