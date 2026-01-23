// leetcode 1970. Last Day Where You Can Still Cross
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
struct DSU
{
    vector<int> p, sz;

    DSU(int n) : p(n), sz(n, 1)
    {
        iota(p.begin(), p.end(), 0);
    }

    int find(int x)
    {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (sz[a] < sz[b])
            swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
    }
};

class Solution
{
public:
    int latestDayToCross(int r, int c, vector<vector<int>> &cells)
    {
        int n = r * c;
        int TOP = n, BOT = n + 1;
        DSU dsu(n + 2);

        vector<vector<int>> g(r, vector<int>(c, 1));
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        auto id = [&](int i, int j)
        {
            return i * c + j;
        };

        for (int day = cells.size() - 1; day >= 0; day--)
        {
            int x = cells[day][0] - 1;
            int y = cells[day][1] - 1;
            g[x][y] = 0;
            int u = id(x, y);

            if (x == 0)
                dsu.unite(u, TOP);
            if (x == r - 1)
                dsu.unite(u, BOT);

            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < r && ny >= 0 && ny < c && g[nx][ny] == 0)
                {
                    dsu.unite(u, id(nx, ny));
                }
            }

            if (dsu.find(TOP) == dsu.find(BOT))
            {
                return day;
            }
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    int r = 2, c = 2;
    vector<vector<int>> cells = {{1, 1}, {2, 1}, {1, 2}, {2, 2}};
    int result = sol.latestDayToCross(r, c, cells);
    cout << "Latest day to cross: " << result << endl;
    return 0;
}