// leetcoode 2141. Maximum Running Time of N Computers
#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;
class Solution
{
public:
    long long maxRunTime(int n, vector<int> &batteries)
    {
        long long ans = accumulate(batteries.begin(), batteries.end(), 0LL);
        priority_queue<int> maxHeap(batteries.begin(), batteries.end());
        while (!maxHeap.empty() && maxHeap.top() > ans / n)
        {
            ans -= maxHeap.top();
            maxHeap.pop();
            n--;
        }
        return ans / n;
    }
};
int main()
{
    Solution sol;
    int n = 2;                         // Example number of computers
    vector<int> batteries = {3, 3, 3}; // Example battery capacities
    long long result = sol.maxRunTime(n, batteries);
    cout << "Maximum running time of " << n << " computers: " << result << endl;
    return 0;
}