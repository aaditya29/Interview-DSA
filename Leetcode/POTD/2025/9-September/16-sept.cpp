// Leetcode 2197

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> replaceNonCoprimes(vector<int> &nums)
    {
        vector<long long> result;

        for (int num : nums)
        {
            long long current = num;

            while (!result.empty())
            {

                long long a = result.back();
                long long b = current;
                while (b != 0)
                {
                    long long temp = b;
                    b = a % b;
                    a = temp;
                }
                long long gcd_val = a;

                if (gcd_val <= 1)
                    break;

                current = (result.back() / gcd_val) * current;
                result.pop_back();
            }

            result.push_back(current);
        }

        vector<int> finalResult;
        for (long long val : result)
        {
            finalResult.push_back((int)val);
        }

        return finalResult;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {6, 4, 3, 2, 7, 6, 2};
    vector<int> result = sol.replaceNonCoprimes(nums);
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl; // Output: [12,7]
    return 0;
}