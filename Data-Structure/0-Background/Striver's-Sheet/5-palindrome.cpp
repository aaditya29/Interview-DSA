// LEETCODE 9. Palindrome Number

#include <iostream>
#include <climits>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        int original = x;
        long long reverse = 0;

        while (x != 0)
        {
            int digit = x % 10;
            x /= 10;
            reverse = reverse * 10 + digit;
        }

        if (reverse > INT_MAX)
        {
            return false;
        }

        return reverse == original;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution obj;
    cout << obj.isPalindrome(n) << endl;
}