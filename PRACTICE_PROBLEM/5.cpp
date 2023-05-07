#include <bits/stdc++.h>
using namespace std;
class Complex
{
    int real, img;

public:
    Complex()
    {
        real = 0;
        img = 0;
    }
    Complex(int r, int i)
    {
        real = r;
        img = i;
    }
    void setValues(int r, int i)
    {
        real = r;
        img = i;
    }
    void print()
    {
        cout << real << " " << img << endl;
    }
    friend Complex add(Complex, Complex);
    friend Complex subtract(Complex, Complex);
};
Complex add(Complex a, Complex b)
{
    Complex c;
    c.real = a.real + b.real;
    c.img = a.img + b.img;
    return c;
}
Complex subtract(Complex a, Complex b)
{
    Complex c;
    c.real = a.real - b.real;
    c.img = a.img - b.img;
    return c;
}
int main()
{
    Complex a(1, 2), b(3, 4), c;
    c = add(a, b);
    c.print();
    c = subtract(a, b);
    c.print();
    return 0;
}