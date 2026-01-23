// leetcode 960. Delete Columns to Make Sorted III
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int n = strs.size();
        int l = strs[0].length();
        vector<int> dp(l);
        fill(dp.begin(), dp.end(), 1);
        int lis = 1;
        for (int j = 1; j < l; j++)
        {
            for (int k = 0; k < j; k++)
            {
                bool valid = true;
                for (int i = 0; i < n; i++)
                {
                    if (strs[i][k] > strs[i][j])
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                {
                    dp[j] = max(dp[j], dp[k] + 1);
                    lis = max(lis, dp[j]);
                }
            }
        }
        return (l - lis);
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"babca", "bbazb"};
    int result = sol.minDeletionSize(strs);
    cout << "Minimum number of columns to delete: " << result << endl;
    return 0;
}