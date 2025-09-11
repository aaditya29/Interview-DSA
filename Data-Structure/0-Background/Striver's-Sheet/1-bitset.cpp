#include <iostream>
#include <bitset>
using namespace std;
int main()
{
    /*
    int a[100];//array of 100 integers with 16 bits each
    char b[100];//array of 100 characters with 8 bits each
    */
    // bitset has only 1 bit for each element
    bitset<5> bt;                   // bitset of size 5 with all bits initialized to 0
    cin >> bt;                      // input 5 bits
    cout << bt.all() << endl;       // check if all bits are 1 and returns true or false
    cout << bt.any() << endl;       // check if any bit is 1 and returns true or false
    cout << bt.count() << endl;     // count number of bits set to 1
    cout << bt.flip() << endl;      // flip all bits
    cout << bt.flip(2) << endl;     // flip bit at index 2
    cout << bt.none() << endl;      // check if no bit is set to 1 and returns true or false
    cout << bt.size() << endl;      // returns size of bitset
    cout << bt.test(2) << endl;     // check if bit at index 2 is 1 or not and returns true or false
    cout << bt.to_ullong() << endl; // convert bitset to unsigned long long
    cout << bt.to_string() << endl; // convert bitset to string
    cout << bt << endl;             // print bitset
    cout << bt.set(1) << endl;      // set bit at index 1 to 1
    cout << bt.set() << endl;       // set all bits to 1
    cout << bt.reset(1) << endl;    // reset bit at index 1 to 0
    cout << bt.reset() << endl;     // reset all bits to 0
    return 0;
}