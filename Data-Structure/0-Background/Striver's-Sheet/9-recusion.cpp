// sum of first n natural numbers using recursion
#include <iostream>
using namespace std;
class Solution
{
public:
    int NnumbersSum(int N)
    {

        if (N == 1)
        {
            return 1;
        }
        return N + NnumbersSum(N - 1);
    }
};
int main()
{
    Solution sol;
    int N = 5; // Example input
    cout << "Sum of first " << N << " natural numbers is: " << sol.NnumbersSum(N) << endl;
    return 0;
}