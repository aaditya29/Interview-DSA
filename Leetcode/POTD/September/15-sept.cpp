// 1935. Maximum Number of Words You Can Type
#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>
using namespace std;

class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());

        stringstream ss(text);
        string word;
        int count = 0;

        while (ss >> word)
        {
            bool canType = true;

            for (char c : word)
            {
                if (broken.count(c))
                {
                    canType = false;
                    break;
                }
            }

            if (canType)
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    Solution sol;
    string text = "hello world";
    string brokenLetters = "ad";
    cout << sol.canBeTypedWords(text, brokenLetters) << endl; // Output: 1
    return 0;
}