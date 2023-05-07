#include <bits/stdc++.h>
using namespace std;
int mul(int a, int b)
{
    return a * b;
}
float mul(float a, float b)
{
    return a * b;
}
float mul(int a, float b)
{
    return a * b;
}
float mul(float a, int b)
{
    return a * b;
}

int main()
{
    cout << mul(2, 3) << endl;
    cout << mul(2.3f, 3.4f) << endl;
    cout << mul(2, 3.4f) << endl;
    cout << mul(2.3f, 3) << endl;
    return 0;
}
