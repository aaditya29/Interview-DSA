// leetcode 3577. Count the Number of Computer Unlocking Permutations
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int countPermutations(vector<int> &c)
    {
        int mod = 1000000007;
        int initial = c[0];
        unordered_map<int, int> mp;
        for (int i : c)
        {
            mp[i]++;
            if ((i == initial) && (mp[i] >= 2))
            {
                return 0;
            }
        }
        for (int i = 1; i < c.size(); i++)
        {
            if (c[i] == initial || c[i] < initial)
            {
                return 0;
            }
        }
        long long ans = 1;
        for (int i = 1; i < c.size(); i++)
        {
            ans = (long long)(ans * i) % mod;
        }
        return ans % mod;
    }
};

int main()
{
    Solution sol;
    vector<int> c = {2, 3, 4}; // Example input
    int result = sol.countPermutations(c);
    cout << "Number of computer unlocking permutations: " << result << endl;
    return 0;
}