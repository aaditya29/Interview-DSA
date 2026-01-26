// 2147. Number of Ways to Divide a Long Corridor
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
    int n, mod = 1e9 + 7;

public:
    int numberOfWays(string s)
    {
        n = s.size();
        long long ans = 1;
        vector<pair<int, int>> groups;
        int countS = 0, first = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'S')
            {
                if (first == -1)
                    first = i;
                else
                {
                    groups.push_back({first, i});
                    first = -1;
                }
                countS++;
            }
        }
        if (countS % 2 != 0 || countS == 0)
            return 0;
        for (int i = 0; i < groups.size() - 1; i++)
            ans = (ans * (groups[i + 1].first - groups[i].second)) % mod;
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "SSPSSPSS";
    int result = sol.numberOfWays(s);
    cout << "Number of ways to divide the corridor: " << result << endl;
    return 0;
}