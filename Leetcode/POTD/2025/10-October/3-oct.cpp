// 407. Trapping Rain Water II
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        if (heightMap.empty() || heightMap[0].empty())
            return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<>>
            pq;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                {
                    pq.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }
        int water = 0, maxHeight = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!pq.empty())
        {
            auto [h, x, y] = pq.top();
            pq.pop();
            maxHeight = max(maxHeight, h);
            for (auto &d : dirs)
            {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny])
                {
                    water += max(0, maxHeight - heightMap[nx][ny]);
                    pq.push({heightMap[nx][ny], nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        return water;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> heightMap = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1}};
    cout << sol.trapRainWater(heightMap) << endl; // Output: 4
    return 0;
}