// leetcode 3606. Coupon Code Validator
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<string> validateCoupons(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
    {
        map<string, int> priority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}};
        vector<pair<int, string>> valid;
        for (int i = 0; i < code.size(); i++)
        {
            if (!isActive[i] || code[i].empty() ||
                !priority.count(businessLine[i]))
            {
                continue;
            }
            bool validCode = true;
            for (char c : code[i])
            {
                if (!isalnum(c) && c != '_')
                {
                    validCode = false;
                    break;
                }
            }
            if (validCode)
            {
                valid.push_back({priority[businessLine[i]], code[i]});
            }
        }
        sort(valid.begin(), valid.end());
        vector<string> result;
        for (auto &p : valid)
        {
            result.push_back(p.second);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> code = {"SAVE10", "GROCERY_5", "PHARMA#20", "RESTAURANT_15"};
    vector<string> businessLine = {"electronics", "grocery", "pharmacy", "restaurant"};
    vector<bool> isActive = {true, true, false, true};
    vector<string> result = sol.validateCoupons(code, businessLine, isActive);
    cout << "Valid coupon codes in order:" << endl;
    for (const string &c : result)
    {
        cout << c << endl;
    }
    return 0;
}