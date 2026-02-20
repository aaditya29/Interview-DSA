// leetcode 3650. Minimum Cost Path with Edge Reversals
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minCost(int n, vector<vector<int>> &edges)
    {
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        vector<vector<pair<int, int>>> adj(n);
        for (auto i : edges)
        {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], 2 * i[2]});
        }
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int n = q.front();
            q.pop();
            for (auto it : adj[n])
            {
                if (dist[n] + it.second < dist[it.first])
                {
                    dist[it.first] = dist[n] + it.second;
                    q.push(it.first);
                }
            }
        }
        return (dist[n - 1] == 1e9) ? -1 : dist[n - 1];
    }
};
