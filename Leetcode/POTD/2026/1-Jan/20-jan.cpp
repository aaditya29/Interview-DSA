// leetcode 3314. Construct the Minimum Bitwise Array I
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < nums[i]; j++)
            {
                if ((j | (j + 1)) == nums[i])
                {
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> result = sol.minBitwiseArray(nums);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}