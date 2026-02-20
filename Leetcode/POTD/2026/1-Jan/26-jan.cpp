// leetcode 1200. Minimum Absolute Difference
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int m = INT_MAX, n = arr.size();
        vector<vector<int>> ans;
        for (int k = 0; k < n - 1; ++k)
        {
            if (arr[k + 1] - arr[k] > m)
                continue;
            if (m > arr[k + 1] - arr[k])
            {
                m = arr[k + 1] - arr[k];
                ans.erase(ans.begin(), ans.end());
            }
            ans.push_back({arr[k], arr[k + 1]});
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {4, 2, 1, 3};
    vector<vector<int>> result = sol.minimumAbsDifference(arr);
    for (const auto &pair : result)
    {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;
    return 0;
}