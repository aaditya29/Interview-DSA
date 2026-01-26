// leetcode 3578. Count Partitions With Max-Min Difference at Most K
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
class Solution
{
public:
    int countPartitions(vector<int> &nums, int k)
    {
        int n = nums.size();
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        vector<long long> prefix(n + 2, 0);
        dp[0] = 1;
        prefix[1] = 1;
        deque<int> maxDq, minDq;
        int left = 0;
        for (int i = 0; i < n; i++)
        {
            while (!maxDq.empty() && nums[maxDq.back()] <= nums[i])
            {
                maxDq.pop_back();
            }
            maxDq.push_back(i);
            while (!minDq.empty() && nums[minDq.back()] >= nums[i])
            {
                minDq.pop_back();
            }
            minDq.push_back(i);
            while (!maxDq.empty() && !minDq.empty() &&
                   nums[maxDq.front()] - nums[minDq.front()] > k)
            {
                left++;
                if (maxDq.front() < left)
                    maxDq.pop_front();
                if (minDq.front() < left)
                    minDq.pop_front();
            }
            long long ways = (prefix[i + 1] - prefix[left] + MOD) % MOD;
            dp[i + 1] = ways;
            prefix[i + 2] = (prefix[i + 1] + ways) % MOD;
        }
        return dp[n];
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {2, 3, 5, 1, 4}; // Example input
    int k = 3;                          // Example k value
    int result = sol.countPartitions(nums, k);
    cout << "Number of partitions with max-min difference at most " << k << ": " << result << endl;
    return 0;
}