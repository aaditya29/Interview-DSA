// leetcode 3234. Count the Number of Substrings With Dominant Ones
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.length();
        long long count = 0;
        long long ones = 0;
        for (char c : s)
        {
            if (c == '1')
            {
                ones++;
            }
            else
            {
                count += ones * (ones + 1) / 2;
                ones = 0;
            }
        }
        count += ones * (ones + 1) / 2;
        vector<int> zeros;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                zeros.push_back(i);
        }
        int m = zeros.size();
        if (m == 0)
            return count;
        int maxZ = sqrt(n);
        for (int z = 1; z <= maxZ && z <= m; z++)
        {
            for (int i = 0; i + z - 1 < m; i++)
            {
                int left = (i == 0) ? -1 : zeros[i - 1];
                int right = (i + z == m) ? n : zeros[i + z];
                int L = zeros[i] - left - 1;
                int R = right - zeros[i + z - 1] - 1;
                long long need = (long long)z * z - (zeros[i + z - 1] - zeros[i] - z + 1);
                long long total = (long long)(L + 1) * (R + 1);
                if (need <= 0)
                {
                    count += total;
                }
                else
                {
                    long long invalid = 0;
                    for (int l = 0; l <= L && l < need; l++)
                    {
                        invalid += min((long long)R + 1, need - l);
                    }
                    count += total - invalid;
                }
            }
        }
        return count;
    }
};
int main()
{
    Solution sol;
    string s = "1101001";
    int result = sol.numberOfSubstrings(s);
    cout << "Number of substrings with dominant ones: " << result << endl;
    return 0;
}