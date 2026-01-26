// Leetcode 1488. Avoid Flood in The City
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        int n = rains.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> fullLakes;
        set<int> dryDays;
        for (int i = 0; i < n; i++)
        {
            if (rains[i] == 0)
            {
                dryDays.insert(i);
                ans[i] = 1;
            }
            else
            {
                int lake = rains[i];
                if (fullLakes.count(lake))
                {
                    int lastRainDay = fullLakes[lake];
                    auto it = dryDays.upper_bound(lastRainDay);

                    if (it == dryDays.end())
                    {
                        return {};
                    }
                    ans[*it] = lake;
                    dryDays.erase(it);
                }
                fullLakes[lake] = i;
                ans[i] = -1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> rains = {1, 2, 0, 0, 2, 1};
    vector<int> result = sol.avoidFlood(rains);
    for (int day : result)
    {
        cout << day << " ";
    }
    cout << endl;
    return 0;
}