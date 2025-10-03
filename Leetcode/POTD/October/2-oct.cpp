// 3100. Water Bottles II

#include <iostream>
using namespace std;

class Solution
{
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int drunk = 0;
        int empty = 0;
        while (numBottles > 0 || empty >= numExchange)
        {
            if (numBottles > 0)
            {
                drunk += numBottles;
                empty += numBottles;
                numBottles = 0;
            }
            if (empty >= numExchange)
            {
                empty -= numExchange;
                numBottles = 1;
                numExchange++;
            }
        }
        return drunk;
    }
};

int main()
{
    Solution sol;
    int numBottles = 9, numExchange = 3;
    cout << sol.maxBottlesDrunk(numBottles, numExchange) << endl; // Output: 13
    return 0;
}