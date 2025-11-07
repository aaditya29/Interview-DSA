// 966. Vowel Spellchecker
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
    {
        unordered_set<string> exactMatch;
        unordered_map<string, string> caseInsensitiveMatch;
        unordered_map<string, string> vowelErrorMatch;
        for (const string &word : wordlist)
        {
            exactMatch.insert(word);
            string lower = toLower(word);
            if (!caseInsensitiveMatch.count(lower))
            {
                caseInsensitiveMatch[lower] = word;
            }
            string pattern = createVowelPattern(lower);
            if (!vowelErrorMatch.count(pattern))
            {
                vowelErrorMatch[pattern] = word;
            }
        }
        vector<string> result;
        result.reserve(queries.size());

        for (const string &query : queries)
        {
            if (exactMatch.count(query))
            {
                result.push_back(query);
                continue;
            }
            string queryLower = toLower(query);
            if (caseInsensitiveMatch.count(queryLower))
            {
                result.push_back(caseInsensitiveMatch[queryLower]);
                continue;
            }

            string queryPattern = createVowelPattern(queryLower);
            if (vowelErrorMatch.count(queryPattern))
            {
                result.push_back(vowelErrorMatch[queryPattern]);
                continue;
            }
            result.push_back("");
        }

        return result;
    }

    string toLower(const string &s)
    {
        string result = s;
        for (char &c : result)
        {
            c = tolower(c);
        }
        return result;
    }

    string createVowelPattern(const string &s)
    {
        string pattern = s;
        for (char &c : pattern)
        {
            if (isVowel(c))
            {
                c = '*';
            }
        }
        return pattern;
    }
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

int main()
{
    Solution sol;
    vector<string> wordlist = {"KiTe", "kite", "hare", "Hare"};
    vector<string> queries = {"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto"};
    vector<string> result = sol.spellchecker(wordlist, queries);
    for (const string &word : result)
    {
        cout << word << " ";
    }
    cout << endl; // Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
    return 0;
}