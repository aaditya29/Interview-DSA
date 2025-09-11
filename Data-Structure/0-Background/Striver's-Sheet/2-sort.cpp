#include <iostream>
using namespace std;
int main()
{

    // sorting array and vectors
    int n;
    cin >> n;
    int arr[n]; // array of size n
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n); // sorts the array in ascending order

    vector<int> v(5, 0); // vector of size 5 with all elements initialized to 0
    for (int i = 0; i < 5; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end()); // sorts the vector in ascending order [)

    // vector -> {1,6,2,7,4} and we want to sort only index from 1 to 3
    // final vector -> {1,2,6,7,4}
    sort(v.begin() + 1, v.begin() + 4); // sorts the vector from index 1 to 3 [)
}