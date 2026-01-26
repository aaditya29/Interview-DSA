// 2654. Minimum Number of Operations to Make All Array Elements Equal to 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);
        if (ones > 0)
        {
            return n - ones;
        }
        int totalGcd = nums[0];
        for (int i = 1; i < n; i++)
        {
            totalGcd = gcd(totalGcd, nums[i]);
        }
        if (totalGcd > 1)
        {
            return -1;
        }
        int minLen = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int currentGcd = nums[i];

            for (int j = i; j < n; j++)
            {
                currentGcd = gcd(currentGcd, nums[j]);
                if (currentGcd == 1)
                {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }
        return (minLen - 1) + (n - 1);
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {2, 6, 3, 4};
    int result = sol.minOperations(nums);
    cout << "Minimum number of operations to make all elements equal to 1: " << result << endl;
    return 0;
}