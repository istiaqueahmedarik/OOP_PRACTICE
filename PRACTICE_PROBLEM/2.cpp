/*
    Consider the following skeleton for problem a, b and c.
class String
{
int len;
char *ptr;
public: //declare constructor, destructor and copy constructor
char get(int ind)

1

{
//return the character at the given index
//Check if index is out of bound
//return 0 in case of error
}
int put(int ind,char c)
{
//Assign character c at position index
//Check if index is out of bound
//return -1 in case of error
}
int getlength()
{
//return the allocation length of the string
}
void print()
{
//print the string upto allocation size
}

};
a. Design a String class that will hold the character values dynamically. Use the
above mentioned skeleton. Declare a non-member function, which will
compare the sum of ASCII characters between two strings. If the sum of
ASCII characters of String 1 is greater than String 2, ‘1’ will be printed
whereas, if the sum of ASCII characters of String 2 is greater than String 1,
‘2’ will be printed. However, for the sum of ASCII characters of two strings
being the same, 0 will be printed by the program.
void compare(String s1,String s2)
{
// print 1; if sum of ASCII character of s1 is greater than s2
// print 2; if sum of ASCII character of s2 is greater than s1
// print 0; if sum of ASCII characters of both string being
the same.
}
b. Declare a non-member function of the class of problem 1, which will join 2
strings and will return the resultant string.
String concat(String s1, String s2){
//string s1=”abcd”
//string 2 = “1234”
//result= = “abcd1234”
//Joins two strings s1 and s2 and returns the resultant
string.
}

2

c. Declare a non-member function of the class of problem 1, which will insert
a particular character at a fixed position of the string and other characters
of the string will be shifted to the right
void insert(String &st, int index, char c) {
//string s1=”abcd”
//insert(s1,0,’k’) //kabc
// Insert char c at index position of st. Shift other characters to
the right.}
*/
#include <bits/stdc++.h>
using namespace std;

class String
{
    int len;
    char *ptr;

public: // declare constructor, destructor and copy constructor
    String()
    {
        len = 0;
        ptr = NULL;
    }
    String(char *s)
    {
        len = strlen(s);
        ptr = new char[len];
        strcpy(ptr, s);
    }
    char get(int ind)

    {
        // return the character at the given index
        // Check if index is out of bound
        // return 0 in case of error
        if (ind >= len)
            return 0;
        return ptr[ind];
    }
    int put(int ind, char c)
    {
        // Assign character c at position index
        // Check if index is out of bound
        // return -1 in case of error
        if (ind >= len)
            return -1;
        ptr[ind] = c;
    }
    int getlength()
    {
        // return the allocation length of the string
        return len;
    }
    void print()
    {
        // print the string upto allocation size
        for (int i = 0; i < len; i++)
            cout << ptr[i];
    }
    friend String concat(String, String);
    friend void insert(String &, int, char);
};
int compare(String s1, String s2)
{
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < s1.getlength(); i++)
    {
        sum1 += s1.get(i);
    }
    for (int i = 0; i < s2.getlength(); i++)
    {
        sum2 += s2.get(i);
    }
    if (sum1 > sum2)
        return 1;
    else if (sum2 > sum1)
        return 2;
    else
        return 0;
}
String concat(String s1, String s2)
{
    String s3;
    s3.len = s1.len + s2.len;
    s3.ptr = new char[s3.len + 2];
    for (int i = 0; i < s1.len; i++)
    {
        s3.ptr[i] = s1.ptr[i];
    }
    for (int i = 0; i < s2.len; i++)
    {
        s3.ptr[i + s1.len] = s2.ptr[i];
    }
    return s3;
}
void insert(String &st, int index, char c)
{
    for (int i = st.len; i > index; i--)
    {
        st.ptr[i] = st.ptr[i - 1];
    }
    st.ptr[index] = c;
    st.len++;
}
int main()
{
    String s1("abcd"), s2("1234");
    cout << compare(s1, s2) << endl;
    String s3 = concat(s1, s2);
    s3.print();
    cout << endl;
    insert(s3, 0, 'k');
    s3.print();

    return 0;
}