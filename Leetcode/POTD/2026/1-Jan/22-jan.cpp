// leetcode 3507. Minimum Pair Removal to Sort Array I
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
public:
    int minimumPairRemoval(vector<int> &nums)
    {
        if (isNonDecreasing(nums))
        {
            return 0;
        }
        int ops = 0;
        while (nums.size() > 1)
        {
            int minSum = INT_MAX;
            int idx = -1;
            for (int i = 0; i < nums.size() - 1; i++)
            {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum)
                {
                    minSum = sum;
                    idx = i;
                }
            }
            nums[idx] = minSum;
            nums.erase(nums.begin() + idx + 1);
            ops++;
            if (isNonDecreasing(nums))
            {
                return ops;
            }
        }
        return ops;
    }
    bool isNonDecreasing(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5, 4, 3, 2, 1};
    int result = sol.minimumPairRemoval(nums);
    cout << result << endl;
    return 0;
}