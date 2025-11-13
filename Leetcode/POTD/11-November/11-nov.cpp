// leetcode 474. Ones and Zeroes
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (const string &s : strs)
        {
            int zeros = 0, ones = 0;
            for (char c : s)
            {
                if (c == '0')
                    zeros++;
                else
                    ones++;
            }
            for (int i = m; i >= zeros; i--)
            {
                for (int j = n; j >= ones; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
int main()
{
    Solution sol;
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
    int result = sol.findMaxForm(strs, m, n);
    cout << "Maximum number of strings that can be formed: " << result << endl;
    return 0;
}