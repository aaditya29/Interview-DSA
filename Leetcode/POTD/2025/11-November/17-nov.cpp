// leetcode 1437. Check If All 1's Are at Least Length K Places Away
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        int lastOneIndex = -k - 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 1)
            {
                if (i - lastOneIndex <= k)
                {
                    return false;
                }
                lastOneIndex = i;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 0, 0, 1, 0, 1};
    int k = 2;
    if (sol.kLengthApart(nums, k))
    {
        cout << "All 1's are at least " << k << " places away." << endl;
    }
    else
    {
        cout << "There are 1's less than " << k << " places apart." << endl;
    }
    return 0;
}