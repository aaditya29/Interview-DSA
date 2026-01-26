// leetcode 961. N-Repeated Element in Size 2N Array
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        int n = nums.size();
        int m = 2 * n;
        vector<int> ans(m);
        for (int i = 0; i < n; i++)
        {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }
        unordered_map<int, int> mpp;
        for (auto &it : ans)
        {
            mpp[it]++;
        }
        for (auto it : mpp)
        {
            if (it.second == n)
            {
                return it.first;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 3};
    int result = sol.repeatedNTimes(nums);
    cout << "The N-repeated element is: " << result << endl;
    return 0;
}