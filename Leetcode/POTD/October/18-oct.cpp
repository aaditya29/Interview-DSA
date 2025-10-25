// Leetcode 3397. Maximum Number of Distinct Elements After Operations
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution
{
public:
    int maxDistinctElements(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int distinct = 0;
        int lastUsed = INT_MIN;
        for (int num : nums)
        {
            int minPossible = num - k;
            int maxPossible = num + k;
            int target = max(minPossible, lastUsed + 1);
            if (target <= maxPossible)
            {
                distinct++;
                lastUsed = target;
            }
        }
        return distinct;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 4, 4, 5};
    int k = 1;
    cout << sol.maxDistinctElements(nums, k) << endl;
    return 0;
}