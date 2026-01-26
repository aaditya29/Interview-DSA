// 1018. Binary Prefix Divisible By 5
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &nums)
    {
        vector<bool> result;
        int current_remainder = 0;
        for (int bit : nums)
        {
            current_remainder = (current_remainder * 2 + bit) % 5;
            result.push_back(current_remainder == 0);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0, 1, 1};
    vector<bool> result = sol.prefixesDivBy5(nums);
    for (bool res : result)
    {
        cout << (res ? "true" : "false") << " ";
    }
    cout << endl;
    return 0;
}