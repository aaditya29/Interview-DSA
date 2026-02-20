// leetcode 3315. Construct the Minimum Bitwise Array II
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> minBitwiseArray(vector<int> &n)
    {
        int s = n.size();
        vector<int> ans(s);
        for (int i = 0; i < s; i++)
        {
            int x = n[i];
            if (!(x & 1))
                ans[i] = -1;
            else if (!(x & (x + 1)))
                ans[i] = x >> 1;
            else
            {
                int temp = 0;
                while (x & (1 << temp))
                    temp++;
                ans[i] = x - (1 << (temp - 1));
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> result = sol.minBitwiseArray(nums);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}