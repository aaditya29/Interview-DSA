// leetcode 85. Maximal Rectangle
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;
        int cols = matrix[0].size();
        vector<int> heights(cols + 1, 0);
        int maxArea = 0;
        for (const auto &row : matrix)
        {
            for (int i = 0; i < cols; i++)
            {
                heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;
            }
            stack<int> s;
            s.push(-1);
            for (int i = 0; i <= cols; i++)
            {
                int currentH = (i < cols) ? heights[i] : 0;
                while (s.top() != -1 && heights[s.top()] >= currentH)
                {
                    int h = heights[s.top()];
                    s.pop();
                    int w = i - s.top() - 1;
                    maxArea = max(maxArea, h * w);
                }
                s.push(i);
            }
        }
        return maxArea;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};
    int result = sol.maximalRectangle(matrix);
    return 0;
}