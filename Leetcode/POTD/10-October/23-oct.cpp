// leetcode 3461. Check If Digits Are Equal in String After Operations I
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    bool hasSameDigits(string s)
    {
        int n = s.length();
        while (n > 2)
        {
            for (int i = 0; i < n - 1; i++)
            {
                s[i] = '0' + (s[i] - '0' + s[i + 1] - '0') % 10;
            }
            n--;
        }
        return s[0] == s[1];
    }
};

int main()
{
    Solution sol;
    string s = "1234";
    if (sol.hasSameDigits(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}