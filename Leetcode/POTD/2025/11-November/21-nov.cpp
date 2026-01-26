// leetcode 1930. Unique Length-3 Palindromic Subsequences
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; i++)
        {
            int idx = s[i] - 'a';
            if (first[idx] == -1)
                first[idx] = i;
            last[idx] = i;
        }
        int count = 0;

        // For each outer character
        for (int c = 0; c < 26; c++)
        {
            if (first[c] != -1 && last[c] > first[c])
            {
                unordered_set<char> middle;
                for (int i = first[c] + 1; i < last[c]; i++)
                {
                    middle.insert(s[i]);
                }
                count += middle.size();
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    string s = "aabca";
    int result = sol.countPalindromicSubsequence(s);
    cout << "The number of unique length-3 palindromic subsequences is: " << result << endl;
    return 0;
}