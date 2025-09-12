// LEETCODE 1134. Armstrong Number
class Solution
{
public:
    bool isArmstrong(int n)
    {
        if (n == 0)
        {
            return true;
        }

        int original = n;
        int count = 0;
        int temp = n;

        while (temp > 0)
        {
            temp /= 10;
            count++;
        }

        int sum = 0;
        temp = n;

        while (temp != 0)
        {
            int digit = temp % 10;

            int power = 1;
            for (int i = 0; i < count; i++)
            {
                power *= digit;
            }
            sum += power;

            temp /= 10;
        }

        return sum == original;
    }
};

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    Solution obj;
    cout << obj.isArmstrong(n) << endl;
}