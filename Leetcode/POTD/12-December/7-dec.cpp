// leetcode Test Result 1523. Count Odd Numbers in an Interval Range
#include <iostream>
using namespace std;
class Solution
{
public:
    int countOdds(int low, int high)
    {
        return (high + 1) / 2 - low / 2;
    }
};

int main()
{
    Solution sol;
    int low = 3;  // Example low value
    int high = 7; // Example high value
    int result = sol.countOdds(low, high);
    cout << "Number of odd numbers between " << low << " and " << high << ": " << result << endl;
    return 0;
}