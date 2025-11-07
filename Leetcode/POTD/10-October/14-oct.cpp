// Leetcode 3349. Adjacent Increasing Subarrays Detection I
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool hasIncreasingSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        for (int a = 0; a + 2 * k <= n; ++a)
        {
            bool firstOk = true, secondOk = true;
            for (int i = a; i < a + k - 1; ++i)
            {
                if (nums[i] >= nums[i + 1])
                {
                    firstOk = false;
                    break;
                }
            }
            if (!firstOk)
                continue;
            for (int i = a + k; i < a + 2 * k - 1; ++i)
            {
                if (nums[i] >= nums[i + 1])
                {
                    secondOk = false;
                    break;
                }
            }
            if (secondOk)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int k = 3;
    bool result = sol.hasIncreasingSubarrays(nums, k);
    cout << (result ? "true" : "false") << endl;
    return 0;
}