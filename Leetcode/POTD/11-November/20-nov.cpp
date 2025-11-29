// leetcode 757. Set Intersection Size At Least Two
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             {
                if(a[1]!=b[1]){
                    return a[1]<b[1];
                }
                return a[0]>b[0]; });

        int ans = 0;
        int p1 = -1, p2 = -1;
        for (const auto &interval : intervals)
        {
            int start = interval[0];
            int end = interval[1];

            if (start > p2)
            {
                ans += 2;
                p2 = end;
                p1 = end - 1;
            }
            else if (start > p1)
            {
                ans += 1;
                p1 = p2;
                p2 = end;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {1, 4}, {2, 5}, {3, 5}};
    int result = sol.intersectionSizeTwo(intervals);
    cout << "The minimum size of the set is: " << result << endl;
    return 0;
}