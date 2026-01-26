// Leetcode 1625. Lexicographically Smallest String After Applying Operations
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string findLexSmallestString(string s, int a, int b)
    {
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);
        string smallest = s;
        while (!q.empty())
        {
            string curr = q.front();
            q.pop();
            smallest = min(smallest, curr);
            string added = curr;
            for (int i = 1; i < curr.length(); i += 2)
            {
                added[i] = '0' + (added[i] - '0' + a) % 10;
            }
            if (!visited.count(added))
            {
                visited.insert(added);
                q.push(added);
            }
            int n = curr.length();
            string rotated = curr.substr(n - b) + curr.substr(0, n - b);
            if (!visited.count(rotated))
            {
                visited.insert(rotated);
                q.push(rotated);
            }
        }
        return smallest;
    }
};
int main()
{
    Solution sol;
    string s = "5525";
    int a = 9, b = 2;
    cout << sol.findLexSmallestString(s, a, b) << endl;
    return 0;
}
