/*
    In this problem, you’ll need to design a Point class that will hold the Cartesian
coordinates. Your class will have two private variables named x and y.
a. Write down appropriate constructors and destructors.
b. Write a member function with the following prototype:
Point * shiftBy(int dx, int dy)
[Suppose a point object is p1(3, 4). Calling p1.shiftBy(2, 6)will shift p1 to
(5, 10), and return itself.]
c. Write a non-member function to calculate the distance between two
functions. It will have the following prototype.
double distance(Point p1, Point p2)
d. Write a print() function to print the coordinates.
Requirement
a. Declare a Point object p1 with values
b. Declare a pointer to Point object named p2.
c. Shift p1 by (2, 5), and hold its reference in p2.
d. Use p2 pointer to print the value of p1
*/

#include <bits/stdc++.h>
using namespace std;

class Point
{
    int x, y;

public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    Point(const Point &p)
    {
        x = p.x;
        y = p.y;
    }
    Point *shiftBy(int dx, int dy)
    {
        x += dx;
        y += dy;
        return this;
    }
    void print()
    {
        cout << x << " " << y << endl;
    }
    friend double distance(Point p1, Point p2);
};

double distance(Point p1, Point p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main()
{
    Point p1(3, 4);
    Point *p2 = p1.shiftBy(2, 6);
    p2->print();
    cout << distance(p1, *p2) << endl;
}