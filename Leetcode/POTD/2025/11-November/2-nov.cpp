// letcode 2257. Count Unguarded Cells in the Grid
class Solution
{
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (auto &g : guards)
        {
            grid[g[0]][g[1]] = 1;
        }
        for (auto &w : walls)
        {
            grid[w[0]][w[1]] = 2;
        }
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (auto &guard : guards)
        {
            int row = guard[0], col = guard[1];
            for (auto &dir : dirs)
            {
                int r = row + dir[0];
                int c = col + dir[1];
                while (r >= 0 && r < m && c >= 0 && c < n)
                {
                    if (grid[r][c] == 1 || grid[r][c] == 2)
                    {
                        break;
                    }
                    grid[r][c] = 3;
                    r += dir[0];
                    c += dir[1];
                }
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    count++;
                }
            }
        }
        return count;
    }
};