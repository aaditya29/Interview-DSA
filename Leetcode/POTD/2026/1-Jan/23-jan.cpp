// leetcode 3510. Minimum Pair Removal to Sort Array II
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int minimumPairRemoval(vector<int> &nums)
    {
        typedef long long ll;
        int n = nums.size();
        if (n <= 1)
        {
            return 0;
        }
        vector<ll> a(nums.begin(), nums.end());
        vector<int> prv(n), nxt(n);
        vector<bool> removed(n, false);

        for (int i = 0; i < n; i++)
        {
            prv[i] = i - 1;
            nxt[i] = i + 1;
        }
        nxt[n - 1] = -1;
        int bad = 0;
        for (int i = 0; i + 1 < n; i++)
        {
            if (a[i] > a[i + 1])
                bad++;
        }
        priority_queue<pair<ll, int>,
                       vector<pair<ll, int>>,
                       greater<pair<ll, int>>>
            pq;
        for (int i = 0; i + 1 < n; i++)
        {
            pq.push({a[i] + a[i + 1], i});
        }
        int ops = 0;
        while (bad > 0)
        {
            auto [sum, i] = pq.top();
            pq.pop();
            if (removed[i] || nxt[i] == -1)
                continue;
            int j = nxt[i];
            if (removed[j] || a[i] + a[j] != sum)
                continue;
            int L = prv[i];
            int R = nxt[j];
            if (L != -1 && a[L] > a[i])
                bad--;
            if (a[i] > a[j])
                bad--;
            if (R != -1 && a[j] > a[R])
                bad--;
            a[i] = sum;
            removed[j] = true;
            nxt[i] = R;
            if (R != -1)
                prv[R] = i;
            if (L != -1 && a[L] > a[i])
                bad++;
            if (R != -1 && a[i] > a[R])
                bad++;
            if (L != -1)
                pq.push({a[L] + a[i], L});
            if (R != -1)
                pq.push({a[i] + a[R], i});

            ops++;
        }
        return ops;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5, 4, 3, 2, 1};
    int result = sol.minimumPairRemoval(nums);
    cout << result << endl;
    return 0;
}