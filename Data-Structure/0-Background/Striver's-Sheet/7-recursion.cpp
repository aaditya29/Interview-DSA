#include <iostream>
using namespace std;

// print 1 to n
class Solution
{
public:
    void printNumbers(int n)
    {
        if (n == 1)
        {
            cout << n << endl;
            return;
        }
        printNumbers(n - 1);
        cout << n << endl;
    }
};

int main()
{
    Solution sol;
    int n = 5; // Example input
    sol.printNumbers(n);
    return 0;
}