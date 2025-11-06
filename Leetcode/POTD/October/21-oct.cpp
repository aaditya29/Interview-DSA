// leetcode 3346. Maximum Frequency of an Element After Performing Operations I
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        if (nums.empty())
            return 0;
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxi + 1, 0);
        for (int num : nums)
        {
            freq[num]++;
        }
        for (int i = 1; i <= maxi; i++)
        {
            freq[i] += freq[i - 1];
        }
        int maxFreq = 0;
        for (int target = mini; target <= maxi; target++)
        {
            int left = max(0, target - k);
            int right = min(maxi, target + k);
            int atTarget = freq[target] - (target > 0 ? freq[target - 1] : 0);
            int inRange = freq[right] - (left > 0 ? freq[left - 1] : 0);
            int canConvert = inRange - atTarget;
            int totalFreq = atTarget + min(canConvert, numOperations);
            maxFreq = max(maxFreq, totalFreq);
        }
        return maxFreq;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 4};
    int k = 1;
    int numOperations = 2;
    cout << sol.maxFrequency(nums, k, numOperations) << endl;
    return 0;
}