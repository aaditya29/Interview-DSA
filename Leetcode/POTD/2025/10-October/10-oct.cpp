// Leetcode 3147. Taking Maximum Energy From the Mystic Dungeon
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
public:
    int maximumEnergy(vector<int> &energy, int k)
    {
        int n = energy.size();
        int ans = INT_MIN;
        for (int r = 0; r < k; ++r)
        {
            int last = r + ((n - 1 - r) / k) * k;
            int cur = 0;
            for (int i = last; i >= r; i -= k)
            {
                cur += energy[i];
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> energy = {1, -2, 3, 4, -10, 5};
    int k = 2;
    int result = sol.maximumEnergy(energy, k);
    cout << result << endl; // Output the result
    return 0;
}