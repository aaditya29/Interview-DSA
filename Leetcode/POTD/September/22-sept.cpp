// leetcode 3005. Count Elements With Maximum Frequency
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        int freq[101] = {0};
        int maxFreq = 1;
        for (int num : nums)
        {
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }

        int result = 0;
        for (int i = 1; i <= 100; i++)
        {
            if (freq[i] == maxFreq)
            {
                result += maxFreq;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 2, 3, 3, 3};
    cout << sol.maxFrequencyElements(nums) << endl; // Output: 3
    return 0;
}