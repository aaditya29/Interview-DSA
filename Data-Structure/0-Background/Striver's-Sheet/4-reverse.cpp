class Solution
{
public:
    int reverse(int x)
    {
        int reverse = 0;

        while (x != 0)
        {
            int digit = x % 10;
            x /= 10;
            if (reverse > numeric_limits<int>::max() / 10 ||
                (reverse == numeric_limits<int>::max() / 10 && digit > 7))
            {
                return 0;
            }

            if (reverse < numeric_limits<int>::min() / 10 ||
                (reverse == numeric_limits<int>::min() / 10 && digit < -8))
            {
                return 0;
            }

            reverse = reverse * 10 + digit;
        }
        return reverse;
    }
};
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    Solution obj;
    cout << obj.reverse(n) << endl;
}