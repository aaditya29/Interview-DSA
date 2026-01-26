// 417. Pacific Atlantic Water Flow
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));
        for (int i = 0; i < m; i++)
        {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }

        for (int j = 0; j < n; j++)
        {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }
        vector<vector<int>> result;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited,
             int r, int c)
    {
        visited[r][c] = true;
        int m = heights.size(), n = heights[0].size();
        int dirs[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto [dr, dc] : dirs)
        {
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                !visited[nr][nc] && heights[nr][nc] >= heights[r][c])
            {
                dfs(heights, visited, nr, nc);
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}};
    vector<vector<int>> result = sol.pacificAtlantic(heights);
    for (const auto &cell : result)
    {
        cout << "[" << cell[0] << ", " << cell[1] << "] ";
    }
    cout << endl;
    return 0;
}