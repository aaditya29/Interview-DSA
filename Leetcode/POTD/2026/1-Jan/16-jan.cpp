// leetcode 2975. Maximum Square Area by Removing Fences From a Field
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximizeSquareArea(int m, int n, vector<int> &hFences, vector<int> &vFences)
    {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        unordered_set<int> hGaps;
        for (int i = 0; i < hFences.size(); i++)
        {
            for (int j = i + 1; j < hFences.size(); j++)
            {
                hGaps.insert(hFences[j] - hFences[i]);
            }
        }
        long long maxSide = -1;
        for (int i = 0; i < vFences.size(); i++)
        {
            for (int j = i + 1; j < vFences.size(); j++)
            {
                int currentGap = vFences[j] - vFences[i];
                if (hGaps.count(currentGap))
                {
                    maxSide = max(maxSide, (long long)currentGap);
                }
            }
        }
        if (maxSide == -1)
        {
            return -1;
        }
        long long MOD = 1e9 + 7;
        return (maxSide * maxSide) % MOD;
    }
};

int main()
{
    Solution sol;
    int m = 5, n = 5;
    vector<int> hFences = {2, 4};
    vector<int> vFences = {1, 3};
    int result = sol.maximizeSquareArea(m, n, hFences, vFences);
    return 0;
}