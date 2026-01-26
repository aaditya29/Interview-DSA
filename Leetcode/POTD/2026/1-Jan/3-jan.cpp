#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int numOfWays(int n)
    {
        const int MOD = 1000000007;
        long long same = 6;
        long long diff = 6;
        for (int i = 2; i <= n; i++)
        {
            long long prevSame = same;
            long long prevDiff = diff;
            same = (3 * prevSame + 2 * prevDiff) % MOD;
            diff = (2 * prevSame + 2 * prevDiff) % MOD;
        }

        return (same + diff) % MOD;
    }
};
int main()
{
    Solution sol;
    int n = 3;
    int result = sol.numOfWays(n);
    cout << "Number of ways to paint the grid: " << result << endl;
    return 0;
}