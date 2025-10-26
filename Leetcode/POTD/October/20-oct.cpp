// Leetcode 2011. Final Value of Variable After Performing Operations
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int X = 0;
        for (const string &op : operations)
        {
            if (op[1] == '+')
            {
                X++;
            }
            else
            {
                X--;
            }
        }
        return X;
    }
};
int main()
{
    Solution sol;
    vector<string> operations = {"--X", "X++", "X++"};
    cout << sol.finalValueAfterOperations(operations) << endl;
    return 0;
}