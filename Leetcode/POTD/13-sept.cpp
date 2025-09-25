// 3541. Find Most Frequent Vowel and Consonant
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Solution
{
public:
    int maxFreqSum(string s)
    {
        unordered_map<char, int> freq;
        for (char c : s)
        {
            freq[c]++;
        }

        int maxVowel = 0;
        int maxConsonant = 0;

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (auto &pair : freq)
        {
            char character = pair.first;
            int frequency = pair.second;

            if (vowels.count(character))
            {

                maxVowel = max(maxVowel, frequency);
            }
            else
            {
                maxConsonant = max(maxConsonant, frequency);
            }
        }

        return maxVowel + maxConsonant;
    }
};

int main()
{
    Solution sol;
    string s = "leetcode";
    cout << sol.maxFreqSum(s) << endl; // Output: 3
    return 0;
}