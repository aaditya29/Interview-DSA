// Leetcode 3321. Find X-Sum of All K-Long Subarrays II
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution
{
public:
    vector<long long> findXSum(vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        vector<long long> answer;
        set<pair<int, int>> top, rest;
        unordered_map<int, int> freq;
        long long topSum = 0;
        auto remove = [&](int value)
        {
            if (freq[value] == 0)
                return;

            pair<int, int> p = {freq[value], value};

            auto it = top.find(p);
            if (it != top.end())
            {
                topSum -= 1LL * freq[value] * value;
                top.erase(it);
                if (!rest.empty())
                {
                    auto best = *rest.rbegin();
                    rest.erase(best);
                    top.insert(best);
                    topSum += 1LL * best.first * best.second;
                }
            }
            else
            {
                rest.erase(p);
            }
        };
        auto add = [&](int value, int cnt)
        {
            if (cnt == 0)
                return;

            pair<int, int> p = {cnt, value};
            if (top.size() < x || p > *top.begin())
            {
                topSum += 1LL * cnt * value;
                top.insert(p);
                if (top.size() > x)
                {
                    auto worst = *top.begin();
                    topSum -= 1LL * worst.first * worst.second;
                    top.erase(worst);
                    rest.insert(worst);
                }
            }
            else
            {
                rest.insert(p);
            }
        };
        int i = 0, j = 0;
        while (j < n)
        {
            if (freq[nums[j]] > 0)
            {
                remove(nums[j]);
            }
            freq[nums[j]]++;
            add(nums[j], freq[nums[j]]);
            if (j - i + 1 == k)
            {
                answer.push_back(topSum);
                remove(nums[i]);
                freq[nums[i]]--;
                if (freq[nums[i]] == 0)
                {
                    freq.erase(nums[i]);
                }
                else
                {
                    add(nums[i], freq[nums[i]]);
                }
                i++;
            }
            j++;
        }
        return answer;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 2, 1, 3};
    int k = 3, x = 2;
    vector<long long> result = sol.findXSum(nums, k, x);
    for (long long val : result)
    {
        cout << val << " ";
    }
    return 0;
}