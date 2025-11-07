// leetcode 2043. Simple Bank System
#include <iostream>
#include <vector>
using namespace std;
class Bank
{
private:
    vector<long long> accounts;
    int n;
    bool isValidAccount(int account)
    {
        return account >= 1 && account <= n;
    }

public:
    Bank(vector<long long> &balance)
    {
        accounts = balance;
        n = balance.size();
    }
    bool transfer(int account1, int account2, long long money)
    {
        if (!isValidAccount(account1) || !isValidAccount(account2))
        {
            return false;
        }
        if (accounts[account1 - 1] < money)
        {
            return false;
        }
        accounts[account1 - 1] -= money;
        accounts[account2 - 1] += money;
        return true;
    }
    bool deposit(int account, long long money)
    {
        if (!isValidAccount(account))
        {
            return false;
        }
        accounts[account - 1] += money;
        return true;
    }
    bool withdraw(int account, long long money)
    {
        if (!isValidAccount(account))
        {
            return false;
        }
        if (accounts[account - 1] < money)
        {
            return false;
        }
        accounts[account - 1] -= money;
        return true;
    }
};

int main()
{
    vector<long long> balance = {10, 100, 20, 50, 30};
    Bank *bank = new Bank(balance);
    cout << bank->withdraw(3, 10) << endl;    // return true, account 3 has enough money
    cout << bank->transfer(5, 1, 20) << endl; // return true, account 5 has enough money
    cout << bank->deposit(5, 20) << endl;     // return true
    cout << bank->transfer(3, 4, 15) << endl; // return false, account 3 has only 10
    cout << bank->withdraw(10, 50) << endl;   // return false, account 10 is invalid
    return 0;
}