#include <bits/stdc++.h>
using namespace std;
class Lines;
class Point
{
    int x, y;

public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    Point()
    {
        x = 0;
        y = 0;
    }
    void print()
    {
        cout << x << " " << y << endl;
    }
    friend class Lines;
    ~Point()
    {
    }
};
class Lines
{
    Point p1, p2;

public:
    Lines()
    {
        p1 = Point();
        p2 = Point();
    }
    Lines(Point p1, Point p2)
    {
        this->p1 = p1;
        this->p2 = p2;
    }
    int getLength()
    {
        return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }
    Point midpoint()
    {
        return Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
    }
    ~Lines()
    {
    }
};

int main()
{
    Point p1(1, 2), p2(3, 4);
    Lines l(p1, p2);
    cout << l.getLength() << endl;
    Point p = l.midpoint();
    p.print();
    return 0;
}