// leetcode 3432. Count Partitions with Even Sum Difference
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int countPartitions(vector<int> &nums)
    {
        int totalSum = 0;
        for (int num : nums)
        {
            totalSum += num;
        }
        return (totalSum % 2 == 0) ? nums.size() - 1 : 0;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4}; // Example input
    int result = sol.countPartitions(nums);
    cout << "Number of partitions with even sum difference: " << result << endl;
    return 0;
}