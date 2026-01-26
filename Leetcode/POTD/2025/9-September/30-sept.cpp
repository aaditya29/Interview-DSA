// 2221. Find Triangular Sum of an Array
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        int n = nums.size();
        for (int len = n; len > 1; len--)
        {
            for (int i = 0; i < len - 1; i++)
            {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
        return nums[0];
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << sol.triangularSum(nums) << endl; // Output: 8
    return 0;
}