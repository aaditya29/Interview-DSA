// leetcode 3190. Find Minimum Operations to Make All Elements Divisible by Three
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int operations = 0;
        for (int num : nums)
        {
            if (num % 3 != 0)
                operations++;
        }
        return operations;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int result = sol.minimumOperations(nums);
    cout << "The minimum operations to make all elements divisible by three is: " << result << endl;
    return 0;
}