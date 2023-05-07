#include <bits/stdc++.h>
#define int long long

using namespace std;

class String
{
    int len;
    char *ptr;

public:
    String();
    String(char *c);
    char get(int i) { return ptr[i]; }
    int put(int i, char c) { i > len || i < 0 ? 0 : ptr[i] = c, 1; }
    int getlength() { return len; }
    void print()
    {
        for (int i = 0; i < len; i++)
            cout << ptr[i];
        cout << endl;
    }
};
String::String(char *c)
{
    len = strlen(c);
    ptr = new char[len + 1];
    strcpy(ptr, c);
}
String::String()
{
    len = 0;
    ptr = NULL;
}

int32_t main()
{

    String a("hello_Motherfuckers!");
    if (a.put(12, '*'))
        cout << "char put success" << endl;
    else
        cout << "char put failure" << endl;
    cout << a.getlength() << endl;
    a.print();
}