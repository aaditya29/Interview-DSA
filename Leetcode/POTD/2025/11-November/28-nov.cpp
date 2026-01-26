// leetcode 2872. Maximum Number of K-Divisible Components
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
    {
        vector<vector<int>> adj_list(n);
        for (const auto &edge : edges)
        {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        int res = 0;
        dfs(0, -1, adj_list, values, k, res);
        return res;
    }

private:
    long long dfs(int node, int parent, vector<vector<int>> &adj_list,
                  vector<int> &values, int k, int &res)
    {
        long long curr_sum = values[node];
        for (int neighbor : adj_list[node])
        {
            if (neighbor == parent)
            {
                continue;
            }
            curr_sum += dfs(neighbor, node, adj_list, values, k, res);
        }
        if (curr_sum % k == 0)
        {
            res++;
            return 0;
        }
        return curr_sum;
    }
};

int main()
{
    Solution sol;
    int n = 5;                                                    // Example number of nodes
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}}; // Example edges
    vector<int> values = {2, 3, 5, 4, 6};                         // Example node values
    int k = 5;                                                    // Example divisor
    int result = sol.maxKDivisibleComponents(n, edges, values, k);
    cout << "Maximum number of K-divisible components: " << result << endl;
    return 0;
}