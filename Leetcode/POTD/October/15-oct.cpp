// Leetcode 3350. Adjacent Increasing Subarrays Detection II
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxIncreasingSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> incLen(n, 1);
        for (int i = n - 2; i >= 0; --i)
        {
            if (nums[i] < nums[i + 1])
            {
                incLen[i] = incLen[i + 1] + 1;
            }
        }
        int maxK = 0;
        for (int i = 0; i < n; ++i)
        {
            maxK = max(maxK, incLen[i] / 2);
            if (i + incLen[i] < n)
            {
                int k = min(incLen[i], incLen[i + incLen[i]]);
                maxK = max(maxK, k);
            }
        }
        return maxK;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int result = sol.maxIncreasingSubarrays(nums);
    cout << result << endl;
    return 0;
}