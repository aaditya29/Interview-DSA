// leetcoe 717. 1-bit and 2-bit Characters
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int i = 0;
        while (i < bits.size() - 1)
        {
            if (bits[i] == 1)
            {
                i += 2;
            }
            else
            {
                i += 1;
            }
        }
        return i == bits.size() - 1;
    }
};

int main()
{
    Solution sol;
    vector<int> bits = {1, 0, 0};
    if (sol.isOneBitCharacter(bits))
    {
        cout << "The last character is a one-bit character." << endl;
    }
    else
    {
        cout << "The last character is not a one-bit character." << endl;
    }
    return 0;
}