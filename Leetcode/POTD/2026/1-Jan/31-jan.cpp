// leetcode 744. Find Smallest Letter Greater Than Target
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char t)
    {
        int n = letters.size();
        int s = 0, e = n - 1;
        char ans;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (letters[mid] > t)
            {
                ans = letters[mid];
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return s == n ? letters[0] : ans;
    }
};

int main()
{
    Solution sol;
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'a';
    char result = sol.nextGreatestLetter(letters, target);
    cout << result << endl;
    return 0;
}