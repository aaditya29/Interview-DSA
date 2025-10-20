// Leetcode 3186. Maximum Total Damage With Spell Casting
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    long long maximumTotalDamage(vector<int> &power)
    {
        unordered_map<long long, long long> freq;
        for (int v : power)
            freq[v]++;
        vector<long long> vals;
        vals.reserve(freq.size());
        for (auto &[val, _] : freq)
            vals.push_back(val);
        sort(vals.begin(), vals.end());
        int m = vals.size();
        if (m == 0)
            return 0;
        vector<long long> dp(m);
        dp[0] = vals[0] * freq[vals[0]];
        for (int i = 1; i < m; ++i)
        {
            long long currentSum = vals[i] * freq[vals[i]];
            long long skip = dp[i - 1];
            int j = upper_bound(vals.begin(), vals.begin() + i, vals[i] - 3) - vals.begin() - 1;
            long long take = currentSum + (j >= 0 ? dp[j] : 0);

            dp[i] = max(skip, take);
        }
        return dp[m - 1];
    }
};

int main()
{
    Solution sol;
    vector<int> power = {1, 2, 2, 3, 4, 5};
    long long result = sol.maximumTotalDamage(power);
    cout << result << endl; // Output the result
    return 0;
}