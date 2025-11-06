// leetcode 1716. Calculate Money in Leetcode Bank
#include <iostream>
using namespace std;
class Solution
{
public:
    int totalMoney(int n)
    {
        int w = n / 7;
        int d = n % 7;
        int weeksSum = w * 28 + 7 * w * (w - 1) / 2;
        int daysSum = d * (w + 1) + d * (d - 1) / 2;
        return weeksSum + daysSum;
    }
};

int main()
{
    Solution sol;
    int n = 20;
    cout << sol.totalMoney(n) << endl;
    return 0;
}