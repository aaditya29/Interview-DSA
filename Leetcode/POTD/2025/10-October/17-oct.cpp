// Leetcode 3003. Maximize the Number of Partitions After Operations
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution
{
private:
    unordered_map<long long, int> memo;
    string s;
    int k, n;
    long long encodeState(int pos, int mask, bool canChange)
    {
        return ((long long)pos << 32) | ((long long)mask << 1) | (canChange ? 1 : 0);
    }
    int solve(int pos, int mask, bool canChange)
    {
        if (pos >= n)
            return 0;
        long long state = encodeState(pos, mask, canChange);
        if (memo.count(state))
            return memo[state];
        int distinctCount = __builtin_popcount(mask);
        int result = 0;
        int newMask = mask | (1 << (s[pos] - 'a'));
        int newDistinct = __builtin_popcount(newMask);

        if (newDistinct <= k)
        {
            result = solve(pos + 1, newMask, canChange);
        }
        else
        {
            result = 1 + solve(pos + 1, 1 << (s[pos] - 'a'), canChange);
        }
        if (canChange)
        {
            for (int ch = 0; ch < 26; ch++)
            {
                if ((1 << ch) == (1 << (s[pos] - 'a')))
                    continue;

                int tryMask = mask | (1 << ch);
                int tryDistinct = __builtin_popcount(tryMask);

                if (tryDistinct <= k)
                {
                    result = max(result, solve(pos + 1, tryMask, false));
                }
                else
                {
                    result = max(result, 1 + solve(pos + 1, 1 << ch, false));
                }
            }
        }
        return memo[state] = result;
    }

public:
    int maxPartitionsAfterOperations(string s, int k)
    {
        this->s = s;
        this->k = k;
        this->n = s.length();
        memo.clear();

        return 1 + solve(0, 0, true);
    }
};

int main()
{
    Solution sol;
    string s = "abcde";
    int k = 2;
    int result = sol.maxPartitionsAfterOperations(s, k);
    cout << result << endl;
    return 0;
}