// leetcode 3433. Count Mentions Per User
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>> &events)
    {

        sort(events.begin(), events.end(), [](const vector<string> &a, const vector<string> &b)
             {
                int na = stoi(a[1]);
                int nb = stoi(b[1]);
    
                if (na != nb)
                    return na < nb;                
                if (a[0] == "OFFLINE" && b[0] != "OFFLINE")
                return true;                    
                if (a[0] != "OFFLINE" && b[0] == "OFFLINE")
                return false;
    
                return false; });
        vector<int> ans(numberOfUsers, 0);
        vector<int> offline(numberOfUsers, 0);

        for (int i = 0; i < events.size(); i++)
        {
            string first = events[i][0];
            int second = stoi(events[i][1]);
            string third = events[i][2];
            if (first == "MESSAGE" && third != "ALL" && third != "HERE")
            {
                stringstream s(third);
                string word;
                while (s >> word)
                {
                    int num = stoi(word.substr(2));
                    ans[num]++;
                }
            }
            else if (first == "MESSAGE" && third == "ALL")
            {
                for (auto &c : ans)
                    c += 1;
            }
            else if (first == "MESSAGE" && third == "HERE")
            {
                for (int c = 0; c < offline.size(); c++)
                {
                    if (offline[c] == 0)
                        ans[c] += 1;
                    else
                    {
                        if (second - offline[c] >= 60)
                            ans[c] += 1;
                    }
                }
            }
            else if (first == "OFFLINE")
            {
                int third = stoi(events[i][2]);
                offline[third] = second;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int numberOfUsers = 3;
    vector<vector<string>> events = {
        {"MESSAGE", "1", "ALL"},
        {"OFFLINE", "2", "1"},
        {"MESSAGE", "61", "HERE"},
        {"MESSAGE", "62", "U0 U2"}};
    vector<int> result = sol.countMentions(numberOfUsers, events);
    cout << "Mentions per user: ";
    for (int count : result)
    {
        cout << count << " ";
    }
    cout << endl;
    return 0;
}