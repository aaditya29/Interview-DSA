// leetcode 1266. Minimum Time Visiting All Points
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int ans = 0;
        for (int i = 1; i < points.size(); i++)
        {
            ans += max(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1]));
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> points = {{1, 1}, {3, 4}, {-1, 0}};
    int result = sol.minTimeToVisitAllPoints(points);
    return 0;
}