// 778. Swim in Rising Water
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<>>
            pq;
        vector<vector<int>> minTime(n, vector<int>(n, INT_MAX));
        pq.push({grid[0][0], 0, 0});
        minTime[0][0] = grid[0][0];
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!pq.empty())
        {
            auto [time, r, c] = pq.top();
            pq.pop();
            if (r == n - 1 && c == n - 1)
            {
                return time;
            }
            if (time > minTime[r][c])
                continue;
            for (auto &dir : dirs)
            {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n)
                {
                    int newTime = max(time, grid[nr][nc]);
                    if (newTime < minTime[nr][nc])
                    {
                        minTime[nr][nc] = newTime;
                        pq.push({newTime, nr, nc});
                    }
                }
            }
        }
        return minTime[n - 1][n - 1];
    }
};