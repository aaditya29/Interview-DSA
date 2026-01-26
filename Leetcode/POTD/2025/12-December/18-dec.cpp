// leetcode 3652. Best Time to Buy and Sell Stock using Strategy
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    long long maxProfit(vector<int> &prices, vector<int> &strategy, int k)
    {
        int n = prices.size();
        vector<long long> prefixSum(n, 0);
        vector<long long> actualTrade(n, 0);
        actualTrade[0] = prices[0] * strategy[0];
        prefixSum[0] = prices[0];
        for (int i = 1; i < n; i++)
        {
            prefixSum[i] += prices[i] + prefixSum[i - 1];
        }
        for (int i = 1; i < n; i++)
        {
            actualTrade[i] += (prices[i] * strategy[i]) + actualTrade[i - 1];
        }
        vector<long long> a;
        for (int i = 0; i <= n - k; i++)
        {
            long long x = actualTrade[i + k - 1] - (i > 0 ? actualTrade[i - 1] : 0);
            long long y = prefixSum[i + k - 1] - prefixSum[(((2 * i) + k) / 2) - 1];

            a.push_back(y - x);
        }
        sort(a.begin(), a.end());
        return max(actualTrade[n - 1], actualTrade[n - 1] + a[a.size() - 1]);
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    vector<int> strategy = {1, 0, 1, 0, 1, 0};
    int k = 2;
    long long result = sol.maxProfit(prices, strategy, k);
    cout << "Maximum Profit: " << result << endl;
    return 0;
}