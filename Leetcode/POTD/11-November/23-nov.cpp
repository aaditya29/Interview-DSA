// leetcode 1262. Greatest Sum Divisible by Three
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxSumDivThree(vector<int> &nums)
    {
        vector<int> dp(3, 0);
        for (int num : nums)
        {
            vector<int> temp = dp;
            for (int i = 0; i < 3; i++)
            {
                int newRemainder = (temp[i] + num) % 3;
                dp[newRemainder] = max(dp[newRemainder], temp[i] + num);
            }
        }
        return dp[0];
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {3, 6, 5, 1, 8};
    int result = sol.maxSumDivThree(nums);
    cout << "The greatest sum divisible by three is: " << result << endl;
    return 0;
}