// leetcode 756. Pyramid Transition Matrix
#include <iostream>
#include <vector>
#include <map>
#include <functional>
using namespace std;
class Solution
{
public:
    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        map<string, string> mp;
        for (auto str : allowed)
        {
            mp[str.substr(0, 2)].push_back(str.back());
        }
        function<bool(int, int)> rec = [&](int ind, int row_left)
        {
            if (row_left == 0)
                return true;
            if (ind == row_left - 1)
                return rec(0, row_left - 1);
            string key = "";
            key.push_back(bottom[ind]);
            key.push_back(bottom[ind + 1]);
            if (mp.find(key) == mp.end())
                return false;
            else
            {
                for (auto c : mp[key])
                {
                    char c1 = bottom[ind];
                    bottom[ind] = c;
                    if (rec(ind + 1, row_left))
                        return true;
                    bottom[ind] = c1;
                }
            }
            return false;
        };
        int n = bottom.size();
        return rec(0, n);
    }
};

int main()
{
    Solution sol;
    string bottom = "XYZ";
    vector<string> allowed = {"XYD", "YZE", "DEA", "FFF"};
    bool result = sol.pyramidTransition(bottom, allowed);
    cout << "Can pyramid be built: " << (result ? "Yes" : "No") << endl;
    return 0;
}