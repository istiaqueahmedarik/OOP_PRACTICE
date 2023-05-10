#include <bits/stdc++.h>
#include <cstring>
using namespace std;

class Database;
class User
{
    char *user;
    long long hash;

public:
    User()
    {
        user = NULL;
        hash = 0LL;
    }

    User(char *s, string s1)
    {
        int n = strlen(s);
        user = new char[n + 1];
        strcpy(user, s);
        long long hs = hash_value(s1);
        hash = hs;
    }

    User(const User &u)
    {
        int n = strlen(u.user);
        user = new char[n + 1];
        strcpy(user, u.user);
        this->hash = u.hash;
    }
    long long hash_value(string pass)
    {
        const int p = 29 % 100;
        int n = pass.length();
        int x = 0;
        for (int i = 0; i < n; i++)
        {
            x += (pass[i] - 'a' + 1) * p * (i + 1);
        }
        return x;
    }

    friend class Database;
    friend bool login(Database, User);
};
class Database
{
    User *users;
    int cur_user;
    int max_user;

public:
    Database()
    {
        users = new User[4];
        users[0] = User("Admin", "admin");
        cur_user = 1;
        max_user = 4;
    }

    void addUser(User ob)
    {
        if (cur_user < max_user)
        {
            users[cur_user++] = ob;
        }
        else
        {

            User *temp = new User[max_user * 2];
            max_user *= 2;
            memcpy(temp, users, sizeof(User) * max_user);
            delete users;
            users = temp;
            users[cur_user++] = ob;
        }
    }
    void print()
    {

        cout << "Current users: " << cur_user << endl;
        cout << "Current user list: \n";
        for (int i = 0; i < cur_user; i++)
        {
            cout << i + 1 << " " << users[i].user << endl;
        }
    }
    friend bool login(Database, User);
};
bool login(Database d, User a)
{
    cout << a.user << " " << a.hash << endl;
    for (int i = 0; i < d.cur_user; i++)
    {
        cout << "it is running: " << d.users[i].user << " " << d.users[i].hash << endl;
        if (strcmp(d.users[i].user, a.user) == 0 && d.users[i].hash == a.hash)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    Database db;
    db.addUser(User("Eva", "green"));
    db.addUser(User("Halle", "beryy"));
    db.addUser(User("Jane", "seymour"));
    db.addUser(User("Rosamund", "pike"));
    db.addUser(User("Monica", "belucci"));
    db.print();
    db.addUser(User("Gemma", "arterton"));
    db.addUser(User("Lea", "seydoux"));
    User test_user1("Rosamund", "pike");
    User test_user2("Rosamund", "berry");
    User test_user3("Samantha", "pike");
    if (login(db, test_user1))
        cout << "Login Successful\n";
    else
        cout << "Login Failed\n";
    if (login(db, test_user2))
        cout << "Login Successful\n";
    else
        cout << "Login Failed\n";
    if (login(db, test_user3))
        cout << "Login Successful\n";
    else
        cout << "Login Failed\n";
    return 0;
}