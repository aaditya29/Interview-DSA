// leetcode 3074. Apple Redistribution into Boxes
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity)
    {
        int appleCapacity = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<int>());
        int sum = 0;
        int count = 0;
        for (int i = 0; i < capacity.size(); i++)
        {
            sum += capacity[i];
            count++;
            if (sum >= appleCapacity)
            {
                break;
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> apple = {10, 20, 30};
    vector<int> capacity = {15, 25, 10, 20, 30};
    int result = sol.minimumBoxes(apple, capacity);
    cout << "Minimum number of boxes required: " << result << endl;
    return 0;
}