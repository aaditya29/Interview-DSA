// leetcode 3583. Count Special Triplets
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int specialTriplets(vector<int> &nums)
    {
        int n = nums.size();
        const int MOD = 1e9 + 7;
        long long ans = 0;
        unordered_map<int, int> left, right;
        for (int i = 2; i < n; i++)
        {
            right[nums[i]]++;
        }
        left[nums[0]] = 1;
        for (int j = 1; j < n - 1; j++)
        {
            int needed = nums[j] * 2;
            ans = (ans + (long long)left[needed] * right[needed]) % MOD;
            left[nums[j]]++;
            right[nums[j + 1]]--;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5}; // Example input
    int result = sol.specialTriplets(nums);
    cout << "Number of special triplets: " << result << endl;
    return 0;
}