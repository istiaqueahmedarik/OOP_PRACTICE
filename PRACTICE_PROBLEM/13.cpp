/*
    In our country it is not possible to transfer money between two different banks.
You need to design a system by which transfers can be done between two different
banks(Such as DBBL and Trust Bank). For Simplicity, ignore the account number and
just think about balance. Transfer can happen in both directions, i.e., from DBBL to
Trust or from Trust to DBBL. This should be specified by user input.
a. Write down two classes that represents 2 different bank accounts such as
DBBL and Trust Bank (all the attributes will be private)
b. Each class will have 1 attribute -Balance
c. Write functions in each class to set and get the values.
d. In the main function you need to take the amount of money a user wants to
transfer.
e. Write one non-member function transferMoney(....) that will update the
Balance of each bank after each transfer.
f. Finally, show the current balance of each bank.
*/

#include <bits/stdc++.h>
using namespace std;
class Trust;
class DBBL
{
    double balance;

public:
    DBBL(double balance)
    {
        this->balance = balance;
    }
    void setBalance(double balance)
    {
        this->balance = balance;
    }
    double getBalance()
    {
        return balance;
    }
    friend void transferMoney(DBBL &, Trust &, double);
};

class Trust
{
    double balance;

public:
    Trust(double balance)
    {
        this->balance = balance;
    }
    void setBalance(double balance)
    {
        this->balance = balance;
    }
    double getBalance()
    {
        return balance;
    }
    friend void transferMoney(DBBL &, Trust &, double);
};

void transferMoney(DBBL &dbbl, Trust &trust, double amount)
{
    dbbl.balance += amount;
    trust.balance -= amount;
}

int main()
{
    DBBL dbbl(1000);
    Trust trust(2000);
    double amount;
    cout << "Enter the amount of money you want to transfer: ";
    cin >> amount;
    transferMoney(dbbl, trust, amount);
    cout << "DBBL balance: " << dbbl.getBalance() << endl;
    cout << "Trust balance: " << trust.getBalance() << endl;
    return 0;
}