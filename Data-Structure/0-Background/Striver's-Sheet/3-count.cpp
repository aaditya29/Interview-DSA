class Solution
{
public:
    int countDigit(int n)
    {
        if (n == 0)
            return 1;
        int count = 0;
        while (n > 0)
        {
            n /= 10;
            count++;
        }
        return count;
    }
};

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    Solution obj;
    cout << obj.countDigit(n) << endl;
}