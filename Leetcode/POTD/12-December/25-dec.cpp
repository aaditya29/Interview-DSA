// leetcode 3075. Maximize Happiness of Selected Children
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        sort(happiness.begin(), happiness.end(), greater<>());
        long long sum = 0;
        for (int i = 0; i < k; i++)
        {
            int store = happiness[i] - i;
            if (store <= 0)
                break;
            sum += store;
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    vector<int> happiness = {5, 3, 8, 6};
    int k = 3;
    long long result = sol.maximumHappinessSum(happiness, k);
    cout << "Maximum happiness sum: " << result << endl;
    return 0;
}