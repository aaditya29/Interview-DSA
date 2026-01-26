class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int totalCost = 0;
        for (int i = 0; i < colors.length() - 1; i++)
        {
            if (colors[i] == colors[i + 1])
            {
                totalCost += min(neededTime[i], neededTime[i + 1]);
                neededTime[i + 1] = max(neededTime[i], neededTime[i + 1]);
            }
        }
        return totalCost;
    }
};
