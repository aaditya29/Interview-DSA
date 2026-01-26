// leetcode 3289. The Two Sneaky Numbers of Digitville
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        int n = nums.size() - 2;
        vector<int> freq(n, 0);
        vector<int> result;
        for (int num : nums)
        {
            freq[num]++;
            if (freq[num] == 2)
            {
                result.push_back(num);
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0, 2, 1, 3, 2, 1};
    vector<int> sneakyNumbers = sol.getSneakyNumbers(nums);
    for (int num : sneakyNumbers)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}