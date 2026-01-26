// leetcode 1390. Four Divisors
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution
{
public:
    int sumFourDivisors(vector<int> &arr)
    {
        int totalSum = 0;
        for (auto num : arr)
        {
            vector<int> factors;
            for (int j = 1; j <= sqrt(num); j++)
            {
                if (num % j == 0)
                {
                    factors.push_back(j);
                    if (j != num / j)
                        factors.push_back(num / j);
                }
            }
            if (factors.size() == 4)
            {
                for (auto x : factors)
                    totalSum += x;
            }
        }
        return totalSum;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {21, 4, 7};
    cout << sol.sumFourDivisors(arr) << endl; // Output: 32
    return 0;
}