// leetcode 3354. Make Array Elements Equal to Zero
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countValidSelections(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                if (simulate(nums, i, -1))
                    count++;
                if (simulate(nums, i, 1))
                    count++;
            }
        }

        return count;
    }

private:
    bool simulate(vector<int> nums, int curr, int dir)
    {
        int n = nums.size();
        while (curr >= 0 && curr < n)
        {
            if (nums[curr] == 0)
            {
                curr += dir;
            }
            else
            {
                nums[curr]--;
                dir = -dir;
                curr += dir;
            }
        }
        for (int num : nums)
        {
            if (num != 0)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 1, 0, 1, 0};
    cout << sol.countValidSelections(nums) << endl;
    return 0;
}