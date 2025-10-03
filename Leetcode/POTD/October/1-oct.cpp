// 1518. Water Bottles
#include <iostream>
using namespace std;

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};

int main()
{
    Solution sol;
    int numBottles = 9, numExchange = 3;
    cout << sol.numWaterBottles(numBottles, numExchange) << endl; // Output: 13
    return 0;
}