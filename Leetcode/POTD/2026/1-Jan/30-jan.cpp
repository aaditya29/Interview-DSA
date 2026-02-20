#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    long long minimumCost(string source, string target, vector<string> &original, vector<string> &changed, vector<int> &cost)
    {
        const long long INF = 1e18;
        unordered_map<string, int> id;
        int idx = 0;
        for (auto &s : original)
            if (!id.count(s))
                id[s] = idx++;
        for (auto &s : changed)
            if (!id.count(s))
                id[s] = idx++;
        int n = idx;
        vector<vector<long long>> dist(n, vector<long long>(n, INF));
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;
        for (int i = 0; i < original.size(); i++)
        {
            int u = id[original[i]];
            int v = id[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        unordered_set<int> lens;
        for (auto &s : original)
            lens.insert(s.size());

        int L = source.size();
        vector<long long> dp(L + 1, INF);
        dp[L] = 0;
        for (int i = L - 1; i >= 0; i--)
        {
            if (source[i] == target[i])
                dp[i] = dp[i + 1];
            for (int len : lens)
            {
                if (i + len > L)
                    continue;

                string s = source.substr(i, len);
                string t = target.substr(i, len);

                if (!id.count(s) || !id.count(t))
                    continue;

                long long c = dist[id[s]][id[t]];
                if (c < INF && dp[i + len] < INF)
                    dp[i] = min(dp[i], c + dp[i + len]);
            }
        }
        return dp[0] == INF ? -1 : dp[0];
    }
};

int main()
{
    Solution sol;
    string source = "abcde";
    string target = "bcdef";
    vector<string> original = {"ab", "cd", "e"};
    vector<string> changed = {"bc", "de", "f"};
    vector<int> cost = {1, 1, 1};
    long long result = sol.minimumCost(source, target, original, changed, cost);
    cout << result << endl;
    return 0;
}