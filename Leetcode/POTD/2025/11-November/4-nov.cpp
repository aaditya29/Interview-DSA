// Leetcode 3318. Find X-Sum of All K-Long Subarrays I
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int calculateXSum(unordered_map<int, int> &freq, int x)
    {
        vector<pair<int, int>> elements;
        elements.reserve(freq.size());
        for (auto &[val, count] : freq)
        {
            elements.push_back({val, count});
        }
        sort(elements.begin(), elements.end(), [](const auto &a, const auto &b)
             {
                if (a.second != b.second) {
                    return a.second > b.second; 
                }
                return a.first > b.first; });
        int xSum = 0;
        int count = min(x, (int)elements.size());
        for (int i = 0; i < count; i++)
        {
            xSum += elements[i].first * elements[i].second;
        }
        return xSum;
    }
    vector<int> findXSum(vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        vector<int> answer;
        unordered_map<int, int> freq;
        for (int r = 0; r < n; r++)
        {
            freq[nums[r]]++;
            if (r >= k)
            {
                int leftElement = nums[r - k];
                freq[leftElement]--;
                if (freq[leftElement] == 0)
                {
                    freq.erase(leftElement);
                }
            }
            if (r >= k - 1)
            {
                answer.push_back(calculateXSum(freq, x));
            }
        }
        return answer;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 2, 1, 3};
    int k = 3, x = 2;
    vector<int> result = sol.findXSum(nums, k, x);
    for (int val : result)
    {
        cout << val << " ";
    }
    return 0;
}