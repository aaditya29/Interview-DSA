#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int maxWater = 0;
        while (left < right)
        {
            int width = right - left;
            int h = min(height[left], height[right]);
            maxWater = max(maxWater, width * h);
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxWater;
    }
};

int main()
{
    Solution sol;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << sol.maxArea(height) << endl; // Output: 49
    return 0;
}