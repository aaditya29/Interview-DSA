// leetcode 2110. Number of Smooth Descent Periods of a Stock
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    long long getDescentPeriods(vector<int> &prices)
    {
        int n = prices.size();
        long long result = 0;
        long long length = 1;
        for (int i = 1; i < n; i++)
        {
            if (prices[i] == prices[i - 1] - 1)
            {
                length++;
            }
            else
            {
                result += length * (length + 1) / 2;
                length = 1;
            }
        }
        result += length * (length + 1) / 2;

        return result;
    }
};
int main()
{
    Solution sol;
    vector<int> prices = {3, 2, 1, 4};
    long long result = sol.getDescentPeriods(prices);
    cout << "Number of smooth descent periods: " << result << endl;
    return 0;
}