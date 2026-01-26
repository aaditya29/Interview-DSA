// leetcode 2402. Meeting Rooms III
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end());
        vector<int> count(n, 0);
        priority_queue<int, vector<int>, greater<int>> free;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
        for (int i = 0; i < n; i++)
            free.push(i);
        for (auto &m : meetings)
        {
            long long start = m[0], end = m[1];
            while (!busy.empty() && busy.top().first <= start)
            {
                free.push(busy.top().second);
                busy.pop();
            }
            if (!free.empty())
            {
                int room = free.top();
                free.pop();
                count[room]++;
                busy.push({end, room});
            }
            else
            {
                auto [finishTime, room] = busy.top();
                busy.pop();
                count[room]++;
                busy.push({finishTime + (end - start), room});
            }
        }
        return max_element(count.begin(), count.end()) - count.begin();
    }
};
int main()
{
    Solution sol;
    int n = 2;
    vector<vector<int>> meetings = {{0, 10}, {1, 5}, {2, 7}, {3, 4}};
    int result = sol.mostBooked(n, meetings);
    cout << "Most booked meeting room: " << result << endl;
    return 0;
}