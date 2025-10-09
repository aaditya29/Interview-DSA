// Leetcode 2300. Successful Pairs of Spells and Potions
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> result(n);
        for (int i = 0; i < n; i++)
        {
            long long minPotion = (success + spells[i] - 1) / spells[i];
            int idx = lower_bound(potions.begin(), potions.end(), minPotion) - potions.begin();
            result[i] = m - idx;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> spells = {10, 20, 30};
    vector<int> potions = {3, 1, 2, 5, 4};
    long long success = 100;
    vector<int> result = sol.successfulPairs(spells, potions, success);
    for (int count : result)
    {
        cout << count << " ";
    }
    cout << endl;
    return 0;
}