#include <bits/stdc++.h>
using namespace std;
class Customer
{
    char *name;
    int vault_no;
    int rank;
    double interest_rate;
    double vault_balance;

public:
    friend Customer find_customer(Customer[], string, int);
    Customer()
    {
        name = NULL;
        vault_no = 0;
        rank = 0;
        interest_rate = 0;
        vault_balance = 0;
    }
    Customer(char *name, int vault_no, int rank, double vault_balance)
    {
        int n = strlen(name);
        this->name = new char[n + 1];
        strcpy(this->name, name);
        this->vault_no = vault_no;
        this->rank = rank;
        if (rank == 1)
            interest_rate = 0.7;
        else if (rank == 2)
            interest_rate = 0.5;
        else if (rank == 3)
            interest_rate = 0.35;
        this->vault_balance = vault_balance;
    }
    double total_balance(int year) { return vault_balance * (1 + interest_rate * year); }
    double interest(int year) { return total_balance(year) - vault_balance; }
    void display(int year)
    {
        cout << "Name: " << name << endl;
        cout << "Vault No: " << vault_no << endl;
        cout << "Rank: " << rank << endl;
        cout << "Interest Rate: " << interest_rate << endl;
        cout << "Vault Balance: " << vault_balance << endl;
        cout << "Total Balance: " << total_balance(year) << endl;
        cout << "Interest: " << interest(year) << endl;
    }
};
class Goblin
{
    char *name;
    string designation;
    double salary;
    Customer *customers;
    int sz;

public:
    friend double Customer::interest(int);
    friend Goblin find_goblin(Goblin[], string, int);

    Goblin()
    {
        name = NULL;
        designation = "";
        salary = 0;
        customers = NULL;
        sz = 0;
    }
    Goblin(char *name, string designation, double salary, Customer *customers, int sz)
    {
        int n = strlen(name);
        this->name = new char[n + 1];
        strcpy(this->name, name);
        this->designation = designation;
        this->salary = salary;
        this->customers = new Customer[sz + 1];
        for (int i = 0; i < sz; i++)
            this->customers[i] = customers[i];
        this->sz = sz;
    }
    double total_income(int year)
    {
        if (name == "Coiner")
            return salary * year;
        int x = 0;
        for (int i = 0; i < sz; i++)
            x += customers[i].interest(i);
        return salary * year + x;
    }
    void display(int year)
    {
        cout << "Name: " << name << endl;
        cout << "Designation: " << designation << endl;
        cout << "Total income: " << salary << endl;
    }
    ~Goblin()
    {
        delete[] name;
        delete[] customers;
    }
};

Goblin find_goblin(Goblin goblins[], string name, int size)
{
    for (int i = 0; i < size; i++)
        if (name == goblins[i].name)
            return goblins[i];
    return Goblin();
}
Customer find_customer(Customer customers[], string name, int sz)
{
    for (int i = 0; i < sz; i++)
        if (name == customers[i].name)
            return customers[i];
    return Customer();
}
int main()
{
    cout << "Enter the numbers of customers: ";
    int n;
    cin >> n;
    Customer *customers = new Customer[n + 1];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the name of customer " << i + 1 << ": ";
        char *name = new char[100];
        string nm;
        cin >> nm;
        for (int j = 0; j < nm.size(); j++)
            name[j] = nm[j];
        cout << "Enter the rank of customer " << i + 1 << ": ";
        int rank;
        cin >> rank;

        cout << "Enter the vault balance of customer " << i + 1 << ": ";
        double vault_balance;
        cin >> vault_balance;
        customers[i] = *(new Customer(name, rank * 30, rank, vault_balance));
    }
    cout << "Enter the numbers of goblins: ";
    int m;
    cin >> m;
    Goblin *goblins = new Goblin[m + 1];

    for (int i = 0; i < m; i++)
    {
        cout << "Enter the name of goblin " << i + 1 << ": ";
        char *name = new char[100];
        string nm;
        cin >> nm;
        for (int j = 0; j < nm.size(); j++)
            name[j] = nm[j];
        cout << "Enter the designation of goblin " << i + 1 << ": ";
        string designation;
        cin >> designation;
        cout << "Enter the salary of goblin " << i + 1 << ": ";
        double salary;
        cin >> salary;
        goblins[i] = *(new Goblin(name, designation, salary, customers, m));
    }
    while (1)
    {
        cout << "See details of a Goblin/customer: ";
        char type;
        cin >> type;
        if (type == 'q')
            break;
        if (type == 'G')
        {
            cout << "Enter the name of the goblin: ";
            string name;
            cin >> name;
            cout << "Enter year: ";
            int year;
            cin >> year;
            Goblin goblin = find_goblin(goblins, name, m);
            goblin.display(year);
        }
        else
        {
            cout << "Enter the name of the customer: ";
            string name;
            cin >> name;
            cout << "Enter year: ";
            int year;
            cin >> year;
            Customer customer = find_customer(customers, name, n);
            customer.display(year);
        }
    }

    delete[] customers;
    delete[] goblins;
}