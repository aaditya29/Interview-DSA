// Leetcode 812. Largest Triangle Area
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution
{
public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        int n = points.size();
        double maxArea = 0.0;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    int x3 = points[k][0], y3 = points[k][1];
                    double area = abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) * 0.5;
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> points = {{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}};
    cout << sol.largestTriangleArea(points) << endl; // Output: 2.00000
    return 0;
}