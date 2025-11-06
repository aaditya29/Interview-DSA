// leetcode 3347. Maximum Frequency of an Element After Performing Operations II
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        unordered_map<int, int> freq;
        map<int, int> diff;
        for (int x : nums)
        {
            freq[x]++;
            diff[x - k]++;
            diff[x + k + 1]--;
            if (!diff.count(x))
                diff[x] = 0;
        }
        int maxFreq = 0, reachable = 0;
        for (auto &[pos, delta] : diff)
        {
            reachable += delta;
            int atPos = freq[pos];
            maxFreq = max(maxFreq, atPos + min(reachable - atPos, numOperations));
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