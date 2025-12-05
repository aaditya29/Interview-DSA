// leetcode 3381. Maximum Subarray Sum With Length Divisible by K
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    long long maxSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long long> minPrefixAtRemainder(k, LLONG_MAX);
        minPrefixAtRemainder[0] = 0;
        long long result = LLONG_MIN;
        long long prefix = 0;
        for (int i = 0; i < n; i++)
        {
            prefix += nums[i];
            int r = (i + 1) % k;
            if (minPrefixAtRemainder[r] != LLONG_MAX)
            {
                result = max(result, prefix - minPrefixAtRemainder[r]);
            }
            minPrefixAtRemainder[r] = min(minPrefixAtRemainder[r], prefix);
        }
        return result;
    }
};
