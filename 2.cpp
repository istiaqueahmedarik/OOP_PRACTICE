#include <bits/stdc++.h>
using namespace std;
class Account;
void transferMoney(int, int, int);

class User
{
    char *id;
    char *name;

public:
    User()
    {
        id = NULL;
        name = NULL;
    }
    User(char *s, char *s1)
    {
        int n = strlen(s);
        id = new char[n + 1];
        strcpy(id, s);
        n = strlen(s1);
        name = new char[n + 1];
        strcpy(name, s1);
    }
    User(const User &u)
    {
        int n = strlen(u.id);
        id = new char[n + 1];
        strcpy(id, u.id);
        n = strlen(u.name);
        name = new char[n + 1];
        strcpy(name, u.name);
    }
    ~User()
    {
        delete[] id;
        delete[] name;
    }
    friend class Account;
    friend void transferMoney(int, int, int);
};
class Account
{
    User *user;
    char *phone;
    int *balance;

public:
    Account()
    {
        user = NULL;
        phone = NULL;
        balance = NULL;
    }
    Account(char *s, char *s1, char *s2)
    {
        user = new User(s, s1);
        int n = strlen(s2);
        phone = new char[n + 1];
        strcpy(phone, s2);
        balance = new int;
        *balance = 500;
    }
    void setId(char *x)
    {
        int n = strlen(x);
        user->id = new char[n + 1];
        strcpy(user->id, x);
    }
    void setName(char *x)
    {
        int n = strlen(x);
        user->name = new char[n + 1];
        strcpy(user->name, x);
    }
    void setPhone(char *x)
    {
        int n = strlen(x);
        phone = new char[n + 1];
        strcpy(phone, x);
    }
    void setBalance(int x)
    {
        balance = new int;
        *balance = x;
    }
    void setBalance(int *x)
    {
        balance = x;
    }
    void print()
    {
        cout << "ID: " << user->id << endl;
        cout << "Name: " << user->name << endl;
        cout << "Phone: " << phone << endl;
        cout << "Balance: " << *balance << endl;
    }
    ~Account()
    {
        delete user;
        delete[] phone;
        delete balance;
    }
    friend void transferMoney(int, int, int);
};
Account acc[4] = {Account("1", "A", "10"),
                  Account("2", "B", "10"),
                  Account("3", "C", "10"),
                  Account("4", "D", "10")};

void transferMoney(int i, int j, int amount)
{
    if (strcmp(acc[i].phone, acc[j].phone) == 0)
    {
        cout << "Invalid transaction" << endl;
        return;
    }
    if (*acc[i].balance >= amount)
    {
        *acc[i].balance -= amount;
        *acc[j].balance += amount;
        cout << "Transaction successful" << endl;
    }
    else
    {
        cout << "Insufficient balance" << endl;
    }
}

int main()
{

    return 0;
}