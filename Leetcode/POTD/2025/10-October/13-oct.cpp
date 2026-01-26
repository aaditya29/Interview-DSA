// Leetcode 2273. Find Resultant Array After Removing Anagrams

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        vector<string> result;
        string prevSorted = "";
        for (const string &word : words)
        {
            string sorted = word;
            sort(sorted.begin(), sorted.end());
            if (sorted != prevSorted)
            {
                result.push_back(word);
                prevSorted = sorted;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> words = {"abba", "baba", "bbaa", "cd", "cd"};
    vector<string> result = sol.removeAnagrams(words);
    for (const string &word : result)
    {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}