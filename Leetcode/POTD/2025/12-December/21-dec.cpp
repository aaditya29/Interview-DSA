// leetcode 955. Delete Columns to Make Sorted II
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int n = strs.size();
        int m = strs[0].size();
        int del = 0;
        vector<bool> maintained(n);
        for (int i = 0; i < m; i++)
        {
            bool ok = 1;
            bool clear = 1;
            vector<bool> mark(n);

            for (int j = 0; j < n - 1; j++)
            {
                if (strs[j][i] > strs[j + 1][i] and !maintained[j])
                {
                    ok = 0;
                    break;
                }
                if (strs[j][i] >= strs[j + 1][i])
                {
                    clear = 0;
                }
                else
                    mark[j] = 1;
            }
            if (ok)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    if (mark[j] == 1)
                        maintained[j] = 1;
                }
            }
            if (!ok)
                del++;
            else if (clear)
                break;
        }
        return del;
    }
};
int main()
{
    Solution sol;
    vector<string> strs = {"ca", "bb", "ac"};
    int result = sol.minDeletionSize(strs);
    cout << "Minimum number of columns to delete: " << result << endl;
    return 0;
}