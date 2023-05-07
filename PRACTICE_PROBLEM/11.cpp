/*
    Problem based on namespace:
We all know about the built in function strlen(strg1). It determines the length of a
particular string strg1 (with spaces). Now you have to make your own function
int func(strg1) in a class that will find the length of a string without the
spaces.
Example:
Input: My name is x.
Built in function Output: 13
Own function Output: 10
*/

#include <bits/stdc++.h>
using namespace std;
class String
{
    char *ptr;
    int len;

public:
    String()
    {
        ptr = NULL;
        len = 0;
    }
    String(char *s)
    {
        len = strlen(s);
        ptr = new char[len];
        strcpy(ptr, s);
    }
    int getlength()
    {
        return len;
    }
    void print()
    {
        for (int i = 0; i < len; i++)
            cout << ptr[i];
    }
    friend int func(String);
};
int func(String s)
{
    int count = 0;
    for (int i = 0; i < s.len; i++)
    {
        if (s.ptr[i] != ' ')
            count++;
    }
    return count;
}

int main()
{
    char str[100];
    cout << "Enter a string: ";
    gets(str);
    String s(str);
    cout << "Length of the string without spaces: " << func(s) << endl;
    return 0;
}