// leetcode 2054. Two Best Non-Overlapping Events
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        int n = events.size();
        vector<pair<pair<int, int>, int>> vp(2 * n);
        for (int i = 0; i < n; i++)
        {
            vp[2 * i] = {{events[i][0], 0}, events[i][2]};
            vp[2 * i + 1] = {{events[i][1], 1}, events[i][2]};
        }
        sort(vp.begin(), vp.end());
        int ans = 0, mx = 0;
        for (auto i : vp)
        {
            if (i.first.second)
                mx = max(mx, i.second);
            else
                ans = max(ans, mx + i.second);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> events = {{1, 3, 2}, {4, 5, 2}, {2, 4, 3}};
    int result = sol.maxTwoEvents(events);
    cout << "Maximum sum of values of two non-overlapping events: " << result << endl;
    return 0;
}