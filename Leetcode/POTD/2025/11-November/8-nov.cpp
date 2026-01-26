// Leetcode 3318. Find X-Sum of All K-Long Subarrays I
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int minimumOneBitOperations(int n)
    {
        int result = n;
        while (n > 0)
        {
            n >>= 1;
            result ^= n;
        }
        return result;
    }
};
int main()
{
    Solution sol;
    int n = 6;
    int result = sol.minimumOneBitOperations(n);
    cout << result << endl;
    return 0;
}