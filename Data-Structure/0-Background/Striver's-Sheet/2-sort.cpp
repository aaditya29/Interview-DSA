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

    // reversing the array and vector
    reverse(arr, arr + n);       // reverses the array
    reverse(v.begin(), v.end()); // reverses the vector

    // Finding max and min element in array and vector
    // for any index i to j give the maximum
    int maxi = INT_MIN;
    // Example: find max in arr from index 0 to n-1
    for (int k = 0; k < n; k++)
    {
        if (arr[k] > maxi)
        {                  // compare with current maximum
            maxi = arr[k]; // update maximum if current element is greater
        }
    }
}