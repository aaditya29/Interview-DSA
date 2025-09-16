#include <iostream>
using namespace std;
int main()
{
    int n; // no of elements
    cin >> n;
    int arr[n]; // array of size n
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];      // input elements
        int hash[13] = {0}; // hash array of size 13 initialized to 0
        for (int i = 0; i < n; i++)
        {
            hash[arr[i]]++; // incrementing the count of the element in hash array
        }
        int q; // no of queries
        cin >> q;
        while (q--)
        {
            int x; // element to be searched
            cin >> x;
            cout << hash[x] << endl; // output the count of the element
        }
        return 0;
    }