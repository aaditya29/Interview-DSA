// 1458. Max Dot Product of Two Subsequences
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        const int NEG_INF = -1000000000;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, NEG_INF));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                int prod = nums1[i - 1] * nums2[j - 1];
                dp[i][j] = max({dp[i - 1][j],
                                dp[i][j - 1],
                                prod + max(0, dp[i - 1][j - 1])});
            }
        }
        return dp[n][m];
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {2, 1, -2, 5};
    vector<int> nums2 = {3, 0, -6};
    int result = sol.maxDotProduct(nums1, nums2);
    return 0;
}