// leetcode 3228. Maximum Number of Operations to Move Ones to the End
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int maxOperations(string s)
    {
        int n = s.length();
        int operations = 0;
        int onesCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                onesCount++;
            }
            else
            {
                if (onesCount > 0)
                {
                    if (i == 0 || s[i - 1] == '1')
                    {
                        operations += onesCount;
                    }
                }
            }
        }
        return operations;
    }
};

int main()
{
    Solution sol;
    string s = "1101001";
    int result = sol.maxOperations(s);
    cout << "Maximum number of operations to move ones to the end: " << result << endl;
    return 0;
}