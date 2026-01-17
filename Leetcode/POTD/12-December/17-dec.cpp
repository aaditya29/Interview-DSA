// leetcode 3573. Best Time to Buy and Sell Stock V
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    long long maximumProfit(vector<int> &prices, int k)
    {
        using ll = long long;
        int n = prices.size();
        vector<vector<vector<ll>>> dp(
            n + 1,
            vector<vector<ll>>(k + 2, vector<ll>(3, -1e15)));
        for (int i = 0; i <= k; i++)
            dp[n][i][0] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int t = 0; t <= k; t++)
            {
                dp[i][t][0] = dp[i + 1][t][0];
                dp[i][t][0] = max(dp[i][t][0], dp[i + 1][t + 1][1] + prices[i]);
                dp[i][t][0] = max(dp[i][t][0], dp[i + 1][t + 1][2] - prices[i]);
                dp[i][t][1] = dp[i + 1][t][1];
                dp[i][t][1] = max(dp[i][t][1], dp[i + 1][t][0] - prices[i]);
                dp[i][t][2] = dp[i + 1][t][2];
                dp[i][t][2] = max(dp[i][t][2], dp[i + 1][t][0] + prices[i]);
            }
        }
        return dp[0][0][0];
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2;
    long long result = sol.maximumProfit(prices, k);
    cout << "Maximum Profit: " << result << endl;
    return 0;
}