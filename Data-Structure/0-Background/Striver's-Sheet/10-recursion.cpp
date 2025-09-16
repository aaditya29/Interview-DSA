// swap array elements using recursion
#include <iostream>
using namespace std;
class Solution
{
public:
    void reverse(int arr[], int n)
    {
        if (n <= 1)
        {
            return;
        }
        swap(arr[0], arr[n - 1]);
        reverse(arr + 1, n - 2);
    }
};

int main()
{
    Solution sol;
    int arr[] = {1, 2, 3, 4, 5}; // Example input
    int n = sizeof(arr) / sizeof(arr[0]);
    sol.reverse(arr, n);
    cout << "Reversed array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}