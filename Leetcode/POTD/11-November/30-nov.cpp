// leetcode 1590. Make Sum Divisible by P
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int n = nums.size();
        int target = 0;
        for (int num : nums)
        {
            target = (target + num) % p;
        }
        if (target == 0)
            return 0;
        unordered_map<int, int> seen;
        seen[0] = -1;
        int ans = n;
        int prefix = 0;
        for (int i = 0; i < n; i++)
        {
            prefix = (prefix + nums[i]) % p;
            int need = (prefix - target + p) % p;
            if (seen.count(need))
            {
                ans = min(ans, i - seen[need]);
            }
            seen[prefix] = i;
        }
        return ans == n ? -1 : ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 1, 4, 2}; // Example input
    int p = 6;                       // Example divisor
    int result = sol.minSubarray(nums, p);
    cout << "Minimum subarray length to remove to make sum divisible by " << p << ": " << result << endl;
    return 0;
}