// print n to 1
#include <iostream>
using namespace std;
class Solution
{
public:
    void printNumbers(int n)
    {
        if (n < 1)
        {
            return;
        }
        cout << n << endl;
        printNumbers(n - 1);
    }
};

int main()
{
    Solution sol;
    int n = 5; // Example input
    sol.printNumbers(n);
    return 0;
}