// leetcode 3370. Smallest Number With All Set Bits
#include <iostream>
using namespace std;
class Solution
{
public:
    int smallestNumber(int n)
    {
        int result = 1;
        while (result < n)
        {
            result = result * 2 + 1;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    int n = 3;
    cout << sol.smallestNumber(n) << endl;
    return 0;
}