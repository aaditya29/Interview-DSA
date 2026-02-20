// leetcode 2976. Minimum Cost to Convert String I
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original,
                          vector<char> &changed, vector<int> &cost)
    {
        const long long INF = 1e9;
        vector<vector<long long>> dist(26, vector<long long>(26, INF));

        for (int i = 0; i < 26; i++)
        {
            dist[i][i] = 0;
        }

        for (int i = 0; i < cost.size(); i++)
        {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }
        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        long long result = 0;
        for (int i = 0; i < source.length(); i++)
        {
            if (source[i] != target[i])
            {
                int from = source[i] - 'a';
                int to = target[i] - 'a';

                if (dist[from][to] >= INF)
                    return -1;
                result += dist[from][to];
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    string source = "abc";
    string target = "bcd";
    vector<char> original = {'a', 'b', 'c'};
    vector<char> changed = {'b', 'c', 'd'};
    vector<int> cost = {1, 1, 1};
    long long result = sol.minimumCost(source, target, original, changed, cost);
    cout << result << endl;
    return 0;
}