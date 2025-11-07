// leetcode 2125. Number of Laser Beams in a Bank
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int result = 0, prev = 0;
        for (auto &row : bank)
        {
            int curr = count(row.begin(), row.end(), '1');
            if (curr)
            {
                result += prev * curr;
                prev = curr;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> bank = {"011001", "000000", "010100", "001000"};
    cout << sol.numberOfBeams(bank) << endl;
    return 0;
}