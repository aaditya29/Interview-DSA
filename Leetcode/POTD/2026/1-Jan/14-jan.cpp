// leetcode 3454. Separate Squares II
#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <algorithm>
using namespace std;
class Solution
{
public:
    double separateSquares(vector<vector<int>> &squares)
    {
        vector<tuple<long long, int, long long, long long>> events;

        for (auto &s : squares)
        {
            long long x = s[0], y = s[1], l = s[2];
            events.emplace_back(y, 1, x, x + l);
            events.emplace_back(y + l, -1, x, x + l);
        }

        sort(events.begin(), events.end());

        multiset<pair<long long, long long>> active;
        vector<double> ys, prefArea;

        auto unionLen = [&]()
        {
            if (active.empty())
                return 0.0;
            double res = 0;
            auto it = active.begin();
            long long curL = it->first, curR = it->second;
            ++it;
            for (; it != active.end(); ++it)
            {
                if (it->first > curR)
                {
                    res += curR - curL;
                    curL = it->first;
                    curR = it->second;
                }
                else
                {
                    curR = max(curR, it->second);
                }
            }
            res += curR - curL;
            return res;
        };

        long long prevY = get<0>(events[0]);
        double totalArea = 0;
        int i = 0, n = events.size();

        while (i < n)
        {
            long long y = get<0>(events[i]);
            double h = y - prevY;
            if (h > 0)
            {
                double w = unionLen();
                totalArea += w * h;
                ys.push_back(prevY);
                prefArea.push_back(totalArea);
            }

            while (i < n && get<0>(events[i]) == y)
            {
                int type = get<1>(events[i]);
                long long x1 = get<2>(events[i]);
                long long x2 = get<3>(events[i]);
                if (type == 1)
                    active.insert({x1, x2});
                else
                    active.erase(active.find({x1, x2}));
                i++;
            }
            prevY = y;
        }

        double target = totalArea / 2.0;

        int idx = lower_bound(prefArea.begin(), prefArea.end(), target) - prefArea.begin();
        double baseY = ys[idx];
        double areaBefore = (idx == 0 ? 0.0 : prefArea[idx - 1]);
        double remaining = target - areaBefore;

        active.clear();
        for (auto &e : events)
        {
            long long y = get<0>(e);
            if (y > baseY)
                break;
            int type = get<1>(e);
            long long x1 = get<2>(e);
            long long x2 = get<3>(e);
            if (type == 1)
                active.insert({x1, x2});
            else
                active.erase(active.find({x1, x2}));
        }

        double width = unionLen();
        return baseY + remaining / width;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> squares = {{0, 0, 2}, {1, 1, 2}};
    double result = sol.separateSquares(squares);
    return 0;
}