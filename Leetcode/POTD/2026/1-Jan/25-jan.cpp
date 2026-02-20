// leetcode 1984. Minimum Difference Between Highest and Lowest of K Scores
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 1)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        if (n == k)
        {
            return nums[n - 1] - nums[0];
        }
        int min_diff = 100000;
        for (int i = 0; i < n; i++)
        {
            if (i + k - 1 < n)
                min_diff = min(min_diff, nums[i + k - 1] - nums[i]);
        }
        return min_diff;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {90};
    int k = 1;
    int result = sol.minimumDifference(nums, k);
    cout << result << endl;
    return 0;
}