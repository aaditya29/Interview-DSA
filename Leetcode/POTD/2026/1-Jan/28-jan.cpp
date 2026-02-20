// leetcode 3651. Minimum Cost Path with Teleportations
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Solution
{
public:
    int minCost(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size(), sz = m * n, ans = INT_MAX;
        vector<int> v(sz), idx(sz), suff(sz), dp0(sz), dp1(sz);
        for (int i = 0; i < sz; ++i)
            idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int i, int j)
             { return grid[i / n][i % n] < grid[j / n][j % n]; });
        for (int i = 0; i < sz; ++i)
            v[i] = grid[idx[i] / n][idx[i] % n];
        for (int i = 0; i <= k; ++i)
        {
            if (i - 1 >= 0)
            {
                int t = INT_MAX;
                for (int j = sz - 1; j >= 0; --j)
                    t = min(t, dp1[idx[j]]), suff[j] = t;
            }
            dp0.swap(dp1), fill(dp1.begin() + 1, dp1.end(), INT_MAX), dp1[0] = 0;
            for (int j = 1; j < sz; ++j)
            {
                dp1[j] = min((j % n) >= 1 ? dp1[j - 1] : dp1[j], j - n >= 0 ? dp1[j - n] : dp1[j]) + grid[j / n][j % n];
                if (i - 1 >= 0)
                {
                    int l = lower_bound(v.begin(), v.end(), grid[j / n][j % n]) - v.begin();
                    dp1[j] = min(dp1[j], suff[l]);
                }
            }
            ans = min(ans, dp1.back());
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{5, 1}, {2, 1}};
    int k = 1;
    int result = sol.minCost(grid, k);
    cout << result << endl;
    return 0;
}