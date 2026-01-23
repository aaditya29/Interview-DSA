// leetcode 2483. Minimum Penalty for a Shop
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int ncount = 0;
        int ycount = 0;
        vector<int> ysuff;
        vector<int> npre;
        npre.push_back(0);
        int n = customers.length();
        int tmp = 0;
        for (int i = 0; i < n; i++)
        {
            if (customers[i] == 'N')
                tmp++;
            npre.push_back(tmp);
        }
        int tmp2 = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (customers[i] == 'Y')
                tmp2++;
            ysuff.push_back(tmp2);
        }
        int idx = 0;
        int ans = INT_MAX;
        reverse(ysuff.begin(), ysuff.end());
        ysuff.push_back(0);
        for (int i = 0; i <= n; i++)
        {
            int tmp5 = npre[i] + ysuff[i];
            if (ans > tmp5)
            {
                idx = i;
                ans = tmp5;
            }
        }
        return idx;
    }
};

int main()
{
    Solution sol;
    string customers = "YYNY";
    int result = sol.bestClosingTime(customers);
    cout << "Best closing time: " << result << endl;
    return 0;
}