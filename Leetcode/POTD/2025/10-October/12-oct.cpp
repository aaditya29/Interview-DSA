// Leetcode 3539. Find Sum of Array Product of Magical Sequences
#include <iostream>
#include <vector>
#include <map>
#include <tuple>
using namespace std;
class Solution
{
private:
    static const int MOD = 1e9 + 7;
    map<tuple<int, int, int, int>, long long> memo;
    vector<int> nums;
    int n;
    long long binomial(int n, int k)
    {
        if (k > n || k < 0)
            return 0;
        if (k == 0 || k == n)
            return 1;
        long long res = 1;
        for (int i = 0; i < k; i++)
        {
            res = res * (n - i) % MOD;
            res = res * modInverse(i + 1, MOD) % MOD;
        }
        return res;
    }
    long long modInverse(long long a, long long m)
    {
        return modPow(a, m - 2, m);
    }
    long long modPow(long long base, long long exp, long long mod)
    {
        long long result = 1;
        base %= mod;
        while (exp > 0)
        {
            if (exp & 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
    long long solve(int r, int setBits, int idx, int carry)
    {
        if (r < 0 || setBits < 0)
            return 0;
        int currentSetBits = __builtin_popcount(carry);
        if (r + currentSetBits < setBits)
            return 0;
        if (r == 0)
        {
            return (__builtin_popcount(carry) == setBits) ? 1 : 0;
        }
        if (idx >= n)
            return 0;
        auto key = make_tuple(r, setBits, idx, carry);
        if (memo.find(key) != memo.end())
        {
            return memo[key];
        }
        long long result = 0;
        for (int t = 0; t <= r; t++)
        {
            long long ways = binomial(r, t);
            long long prod = modPow(nums[idx], t, MOD);
            int newCarry = (carry + t) / 2;
            int newSetBits = setBits - ((carry + t) % 2);
            long long contribution = (ways * prod) % MOD;
            contribution = (contribution * solve(r - t, newSetBits, idx + 1, newCarry)) % MOD;

            result = (result + contribution) % MOD;
        }
        memo[key] = result;
        return result;
    }

public:
    int magicalSum(int m, int k, vector<int> &nums)
    {
        this->nums = nums;
        this->n = nums.size();
        memo.clear();
        return solve(m, k, 0, 0);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    int m = 3;
    int k = 2;
    int result = sol.magicalSum(m, k, nums);
    cout << result << endl; // Output the result
    return 0;
}