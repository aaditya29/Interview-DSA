// leetcode 2943. Maximize Area of Square Hole in Grid
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
private:
    int getMaxConsecutiveBars(vector<int> &bars)
    {
        if (bars.empty())
        {
            return 1;
        }
        sort(bars.begin(), bars.end());
        int maxConsecutive = 1;
        int currentConsecutive = 1;
        for (int i = 1; i < bars.size(); i++)
        {
            if (bars[i - 1] + 1 == bars[i])
            {
                currentConsecutive++;
                maxConsecutive = max(maxConsecutive, currentConsecutive);
            }
            else
            {
                currentConsecutive = 1;
            }
        }
        return maxConsecutive;
    }

public:
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
    {
        int maxHGap = getMaxConsecutiveBars(hBars);
        int maxVGap = getMaxConsecutiveBars(vBars);
        int hSide = maxHGap + 1;
        int vSide = maxVGap + 1;
        int side = min(hSide, vSide);
        return side * side;
    }
};

int main()
{
    Solution sol;
    int n = 5, m = 5;
    vector<int> hBars = {2, 4};
    vector<int> vBars = {1, 3};
    int result = sol.maximizeSquareHoleArea(n, m, hBars, vBars);
    return 0;
}