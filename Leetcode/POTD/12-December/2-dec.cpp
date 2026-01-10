// leetcode 3623. Count Number of Trapezoids I
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    const int MOD = 1e9 + 7;
    long long ncr(int n)
    {
        if (n < 2)
            return 0;
        return 1LL * n * (n - 1) / 2;
    }
    int countTrapezoids(vector<vector<int>> &points)
    {
        map<int, int> mp;
        for (auto it : points)
        {
            mp[it[1]]++;
        }
        int possiblePoints = 0;
        int ans = 0;
        for (auto it : mp)
        {
            ans = (ans + possiblePoints * ncr(it.second)) % MOD;
            possiblePoints = possiblePoints + ncr(it.second);
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> points = {{1, 1}, {2, 3}, {3, 1}, {4, 3}}; // Example input
    int result = sol.countTrapezoids(points);
    cout << "Number of trapezoids: " << result << endl;
    return 0;
}