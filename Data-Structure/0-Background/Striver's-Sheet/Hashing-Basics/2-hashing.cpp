// hashing using map
#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n; // no of elements
    cin >> n;
    int arr[n];        // array of size n
    map<int, int> mpp; // map to store the count of elements
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // input elements
        mpp[arr[i]]++; // incrementing the count of the element in map
    }

    int q; // no of queries
    cin >> q;
    while (q--)
    {
        int x; // element to be searched
        cin >> x;
        cout << mpp[x] << endl; // output the count of the element
    }
}