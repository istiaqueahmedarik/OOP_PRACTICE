/*
    In this problem, you’ll need to design a Stack class that will hold the integer values
dynamically. Use the following skeleton of Stack class.
class Stack
{
int *p; int len;
public:
Stack(int n);//n = size of the stack
~Stack(){delete [ ]p;}
initStack(int *ara)//init the stack with the values of ara
printStack()//print the values of stack
...//Write more methods if necessary
};
void printSum(Stack s)//non-member function, prints the sum of
elements of s.
*/

#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int *p;
    int len;

public:
    Stack(int n)
    {
        len = n;
        p = new int[n];
    }
    ~Stack()
    {
        delete[] p;
    }
    void initStack(int *ara)
    {
        for (int i = 0; i < len; i++)
        {
            p[i] = ara[i];
        }
    }
    void printStack()
    {
        for (int i = 0; i < len; i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    friend void printSum(Stack s);
};

void printSum(Stack s)
{
    int sum = 0;
    for (int i = 0; i < s.len; i++)
    {
        sum += s.p[i];
    }
    cout << sum << endl;
}

int main()
{
    int ara[] = {1, 2, 3, 4, 5};
    Stack s(5);
    s.initStack(ara);
    s.printStack();
    printSum(s);
    return 0;
}