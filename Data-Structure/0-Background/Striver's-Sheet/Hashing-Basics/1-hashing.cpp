#include <iostream>
using namespace std;

int main()
{
    string s;            // input string
    cin >> s;            // example: "hello"
    int hash[256] = {0}; // hash array of size 256 initialized to 0
    for (int i = 0; i < s.length(); i++)
    {
        hash[s[i]]++; // incrementing the count of the character in hash array

        int q; // no of queries
        cin >> q;
        while (q--)
        {
            char c;                  // character to be searched
            cin >> c;                // example: 'h'
            cout << hash[c] << endl; // output the count of the character
        }
        return 0;
    }