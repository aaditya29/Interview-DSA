// leetcode 2092. Find All People With Secret
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        sort(meetings.begin(), meetings.end(), [](const auto &a, const auto &b)
             { return a[2] < b[2]; });
        vector<bool> knowsSecret(n, false);
        knowsSecret[0] = true;
        knowsSecret[firstPerson] = true;
        int m = meetings.size();
        int i = 0;
        while (i < m)
        {
            int currentTime = meetings[i][2];
            unordered_map<int, vector<int>> graph;
            set<int> people;
            while (i < m && meetings[i][2] == currentTime)
            {
                int x = meetings[i][0];
                int y = meetings[i][1];
                graph[x].push_back(y);
                graph[y].push_back(x);
                people.insert(x);
                people.insert(y);
                i++;
            }
            queue<int> q;
            set<int> visited;
            for (int person : people)
            {
                if (knowsSecret[person])
                {
                    q.push(person);
                    visited.insert(person);
                }
            }
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                for (int neighbor : graph[curr])
                {
                    if (!visited.count(neighbor))
                    {
                        visited.insert(neighbor);
                        knowsSecret[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            if (knowsSecret[i])
            {
                result.push_back(i);
            }
        }
        return result;
    }
};
int main()
{
    Solution sol;
    int n = 6;
    vector<vector<int>> meetings = {{1, 2, 5}, {2, 3, 8}, {1, 5, 10}};
    int firstPerson = 1;
    vector<int> result = sol.findAllPeople(n, meetings, firstPerson);
    cout << "People who know the secret: ";
    for (int person : result)
    {
        cout << person << " ";
    }
    cout << endl;
    return 0;
}