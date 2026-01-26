// leetcode 944. Delete Columns to Make Sorted
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int ans = 0;
        int m = strs[0].size();
        int n = strs.size();
        for (int i = 0; i < m; i++)
        {
            int j = 0;
            while (j < n - 1)
            {
                if (strs[j][i] > strs[j + 1][i])
                {
                    ans++;
                    break;
                }
                j++;
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<string> strs = {"cba", "daf", "ghi"};
    int result = sol.minDeletionSize(strs);
    cout << "Minimum number of columns to delete: " << result << endl;
    return 0;
}