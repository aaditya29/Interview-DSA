// leetcode 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool verify(int x, int y, int len, int tgt, vector<vector<int>> &g)
    {
        int sm = 0;
        for (int i = x; i < x + len; i++)
        {
            for (int j = y; j < y + len; j++)
            {
                sm += g[i][j];
                if (sm > tgt)
                    return 0;
            }
        }
        return 1;
    }

    bool check(int l, int tgt, vector<vector<int>> &g)
    {
        int n = g.size(), m = g[0].size();
        for (int i = 0; i <= n - l; i++)
        {
            for (int j = 0; j <= m - l; j++)
            {
                if (verify(i, j, l, tgt, g))
                {
                    return 1;
                }
            }
        }
        return 0;
    }
    int maxSideLength(vector<vector<int>> &mat, int threshold)
    {
        int n = mat.size(), m = mat[0].size();
        int ans = 0;
        int low = 1, high = min(n, m);
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (check(mid, threshold, mat))
            {
                ans = max(ans, mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> mat = {{1, 1, 3, 2, 4}, {1, 1, 3, 2, 4}, {1, 1, 3, 2, 4}};
    int threshold = 4;
    int result = sol.maxSideLength(mat, threshold);
    return 0;
}