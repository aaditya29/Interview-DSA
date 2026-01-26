// leetcode 3512. Minimum Operations to Make Array Sum Divisible by K
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        long long sum = 0;
        for (int num : nums)
        {
            sum += num;
        }
        return sum % k;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 1, 4, 2}; // Example input
    int k = 6;                       // Example divisor
    int result = sol.minOperations(nums, k);
    cout << "Minimum operations to make array sum divisible by " << k << ": " << result << endl;
    return 0;
}