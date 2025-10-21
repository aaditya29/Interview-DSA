// leetcode 2598. Smallest Missing Non-negative Integer After Operations
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findSmallestInteger(vector<int> &nums, int value)
    {
        unordered_map<int, int> remainderCount;
        for (int num : nums)
        {
            int remainder = ((num % value) + value) % value;
            remainderCount[remainder]++;
        }
        int mex = 0;
        while (true)
        {
            int needed = mex % value;
            if (remainderCount[needed] > 0)
            {
                remainderCount[needed]--;
                mex++;
            }
            else
            {
                break;
            }
        }
        return mex;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, -10, 7, 13, 6, 8};
    int value = 5;
    int result = sol.findSmallestInteger(nums, value);
    cout << result << endl;
    return 0;
}