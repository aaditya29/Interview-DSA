// leetcode 1015. Smallest Integer Divisible by K
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int smallestRepunitDivByK(int k)
    {
        if (k % 2 == 0 || k % 5 == 0)
        {
            return -1;
        }
        int remainder = 0;
        for (int length = 1; length <= k; length++)
        {
            remainder = (remainder * 10 + 1) % k;
            if (remainder == 0)
            {
                return length;
            }
        }
        return -1;
    }
};
int main()
{
    Solution sol;
    int k = 3; // Example input
    int result = sol.smallestRepunitDivByK(k);
    if (result != -1)
    {
        cout << "The smallest integer divisible by " << k << " is of length: " << result << endl;
    }
    else
    {
        cout << "No such integer exists." << endl;
    }
    return 0;
}