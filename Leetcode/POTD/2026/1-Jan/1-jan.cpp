// leetcode 66. Plus One
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> ans;
        int n = digits.size();
        int rem = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            int s = rem + digits[i];
            rem = s / 10;
            ans.push_back(s % 10);
        }
        if (rem)
            ans.push_back(rem);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> digits = {9, 9, 9};
    vector<int> result = sol.plusOne(digits);
    cout << "Result after adding one: ";
    for (int digit : result)
    {
        cout << digit << " ";
    }
    cout << endl;
    return 0;
}