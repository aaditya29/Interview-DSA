// Leetcode 3494. Find the Minimum Amount of Time to Brew Potions
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution
{
public:
    long long minTime(vector<int> &skill, vector<int> &mana)
    {
        const int n = skill.size(), m = mana.size();
        partial_sum(skill.begin(), skill.end(), skill.begin());
        const int skill0 = skill[0];
        long long startTime = 0;
        for (int j = 1; j < m; j++)
        {
            const long long currentMana = mana[j];
            const long long previousMana = mana[j - 1];
            long long minGap = skill0 * previousMana;
            for (int i = 1; i < n; i++)
            {
                long long gapAtWizard = skill[i] * previousMana -
                                        skill[i - 1] * currentMana;
                minGap = max(minGap, gapAtWizard);
            }
            startTime += minGap;
        }
        return startTime + (long long)skill.back() * mana.back();
    }
};

int main()
{
    Solution sol;
    vector<int> skill = {2, 3, 5};
    vector<int> mana = {3, 2, 4};
    long long result = sol.minTime(skill, mana);
    cout << result << endl; // Output the result
    return 0;
}