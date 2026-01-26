// leetcode 3542. Minimum Operations to Convert All Elements to Zero
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        vector<int> stack;
        int operations = 0;
        for (int a : nums)
        {
            while (!stack.empty() && stack.back() > a)
            {
                stack.pop_back();
            }
            if (a == 0)
            {
                stack.clear();
                continue;
            }
            if (stack.empty() || stack.back() < a)
            {
                ++operations;
                stack.push_back(a);
            }
        }
        return operations;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 5, 2, 4, 1};
    int result = sol.minOperations(nums);
    cout << "Minimum operations to convert all elements to zero: " << result << endl;
    return 0;
}