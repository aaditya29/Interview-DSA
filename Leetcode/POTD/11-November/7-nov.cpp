// Leetcode 2528. Maximize the Minimum Powered City
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    long long maxPower(vector<int> &stations, int r, int k)
    {
        int n = stations.size();
        vector<long long> power(n, 0);
        long long windowSum = 0;
        for (int i = 0; i <= min(r, n - 1); i++)
        {
            windowSum += stations[i];
        }
        power[0] = windowSum;
        for (int i = 1; i < n; i++)
        {
            if (i + r < n)
            {
                windowSum += stations[i + r];
            }
            if (i - r - 1 >= 0)
            {
                windowSum -= stations[i - r - 1];
            }
            power[i] = windowSum;
        }
        long long low = *min_element(power.begin(), power.end());
        long long high = low + k;
        long long answer = low;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (canAchieveOptimized(power, n, r, k, mid))
            {
                answer = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return answer;
    }

private:
    bool canAchieveOptimized(vector<long long> &power, int n, int r,
                             long long k, long long target)
    {
        vector<long long> diff(n + 1, 0);
        long long used = 0;
        long long currentExtra = 0;
        for (int i = 0; i < n; i++)
        {
            currentExtra += diff[i];
            long long currentPower = power[i] + currentExtra;
            if (currentPower < target)
            {
                long long needed = target - currentPower;
                int placeAt = min(n - 1, i + r);
                int leftEffect = max(0, placeAt - r);
                int rightEffect = min(n - 1, placeAt + r);
                diff[leftEffect] += needed;
                diff[rightEffect + 1] -= needed;
                currentExtra += needed;
                used += needed;
                if (used > k)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> stations = {1, 2, 4, 5, 0};
    int r = 1, k = 2;
    long long result = sol.maxPower(stations, r, k);
    cout << result << endl;
    return 0;
}