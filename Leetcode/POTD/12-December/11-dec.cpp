// leetcode 3531. Count Covered Buildings
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    int countCoveredBuildings(int n, vector<vector<int>> &buildings)
    {
        map<int, pair<int, int>> rowRange;
        map<int, pair<int, int>> colRange;
        for (auto &b : buildings)
        {
            int x = b[0], y = b[1];
            if (rowRange.count(x))
            {
                rowRange[x].first = min(rowRange[x].first, y);
                rowRange[x].second = max(rowRange[x].second, y);
            }
            else
            {
                rowRange[x] = {y, y};
            }
            if (colRange.count(y))
            {
                colRange[y].first = min(colRange[y].first, x);
                colRange[y].second = max(colRange[y].second, x);
            }
            else
            {
                colRange[y] = {x, x};
            }
        }
        int result = 0;
        for (auto &b : buildings)
        {
            int x = b[0], y = b[1];
            if (rowRange[x].first < y && rowRange[x].second > y &&
                colRange[y].first < x && colRange[y].second > x)
            {
                result++;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    int n = 5;
    vector<vector<int>> buildings = {{1, 2}, {2, 2}, {3, 2}, {2, 1}, {2, 3}};
    int result = sol.countCoveredBuildings(n, buildings);
    cout << "Number of covered buildings: " << result << endl;
    return 0;
}