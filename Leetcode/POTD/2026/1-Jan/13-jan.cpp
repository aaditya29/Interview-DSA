// 3453. Separate Squares I
#include <iostream>
using namespace std;
class Solution
{
public:
    double separateSquares(vector<vector<int>> &squares)
    {
        int n = squares.size();

        double total = 0;

        vector<tuple<int, int, int>> events;

        for (int i = 0; i < n; i++)
        {
            int y = squares[i][1];
            int l = squares[i][2];
            events.push_back({y, l, 1});
            events.push_back({y + l, l, -1});
            total += 1.0 * l * l;
        }

        sort(events.begin(), events.end(), [&](tuple<int, int, int> &a, tuple<int, int, int> &b)
             { return get<0>(a) < get<0>(b); });

        double covered_width = 0;
        double covered_area = 0;
        double prev_height = 0;

        for (auto [y, l, delta] : events)
        {
            cout << y << " y " << endl;
            double diff = y - prev_height;
            double area = covered_width * diff;
            //  cout<<covered_area+area<<" "<<total<<endl;
            if (2.0 * (covered_area + area) >= total)
            {
                return prev_height + (total - 2 * covered_area) / (2.0 * covered_width);
            }
            covered_width += delta * l;
            covered_area += area;
            prev_height = y;
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> squares = {{0, 0, 2}, {1, 1, 2}};
    double result = sol.separateSquares(squares);
    return 0;
}