// Leetcode 166. Fraction to Recurring Decimal
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
            return "0";
        string result = "";
        if ((numerator < 0) ^ (denominator < 0))
        {
            result += "-";
        }
        long num = abs((long)numerator);
        long den = abs((long)denominator);
        result += to_string(num / den);
        num %= den;
        if (num == 0)
            return result;
        result += ".";
        unordered_map<long, int> remainderMap;
        while (num != 0)
        {
            if (remainderMap.find(num) != remainderMap.end())
            {
                int index = remainderMap[num];
                result.insert(index, "(");
                result += ")";
                break;
            }
            remainderMap[num] = result.length();
            num *= 10;
            result += to_string(num / den);
            num %= den;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    int numerator = 4, denominator = 333;
    cout << sol.fractionToDecimal(numerator, denominator) << endl; // Output: "0.(012)"
    return 0;
}