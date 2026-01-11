// leetcode 1925. Count Square Sum Triples
#include <iostream>
#include <cmath>
using namespace std;
class Solution
{
public:
    int countTriples(int n)
    {
        int count = 0;
        for (int a = 1; a <= n; a++)
        {
            for (int b = 1; b <= n; b++)
            {
                int cSquared = a * a + b * b;
                int c = sqrt(cSquared);
                if (c <= n && c * c == cSquared)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    int n = 5; // Example input
    int result = sol.countTriples(n);
    cout << "Number of square sum triples for n = " << n << ": " << result << endl;
    return 0;
}