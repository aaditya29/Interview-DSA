// leetcode 3625. Count Number of Trapezoids II
#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution
{
public:
    int countTrapezoids(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n < 4)
        {
            return 0;
        }
        map<pair<int, int>, int> slope_counts;
        map<tuple<int, int, long long>, int> slope_line_counts;
        map<pair<int, int>, int> vector_counts;
        map<tuple<int, int, long long>, int> vector_line_counts;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                long long dx = points[j][0] - points[i][0];
                long long dy = points[j][1] - points[i][1];
                long long g = std::gcd(abs(dx), abs(dy));
                long long s_dx = dx / g;
                long long s_dy = dy / g;
                if (s_dx < 0 || (s_dx == 0 && s_dy < 0))
                {
                    s_dx = -s_dx;
                    s_dy = -s_dy;
                }
                long long C = s_dx * points[i][1] - s_dy * points[i][0];

                slope_counts[{(int)s_dy, (int)s_dx}]++;
                slope_line_counts[{(int)s_dy, (int)s_dx, C}]++;
                long long v_dx = dx;
                long long v_dy = dy;
                if (v_dx < 0 || (v_dx == 0 && v_dy < 0))
                {
                    v_dx = -v_dx;
                    v_dy = -v_dy;
                }

                vector_counts[{(int)v_dy, (int)v_dx}]++;
                vector_line_counts[{(int)v_dy, (int)v_dx, C}]++;
            }
        }
        long long total_parallel_pairs = 0;
        for (auto const &[key, count] : slope_counts)
        {
            if (count >= 2)
            {
                total_parallel_pairs += (long long)count * (count - 1) / 2;
            }
        }
        for (auto const &[key, count] : slope_line_counts)
        {
            if (count >= 2)
            {

                total_parallel_pairs -= (long long)count * (count - 1) / 2;
            }
        }
        long long total_vector_pairs = 0;
        for (auto const &[key, count] : vector_counts)
        {
            if (count >= 2)
                total_vector_pairs += (long long)count * (count - 1) / 2;
        }
        for (auto const &[key, count] : vector_line_counts)
        {
            if (count >= 2)
                total_vector_pairs -= (long long)count * (count - 1) / 2;
        }
        return (int)(total_parallel_pairs - (total_vector_pairs / 2));
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> points = {{1, 1}, {2, 3}, {3, 1}, {4, 3}}; // Example input
    int result = sol.countTrapezoids(points);
    cout << "Number of trapezoids: " << result << endl;
    return 0;
}