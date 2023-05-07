/*
 Solve the problem using Object Oriented Paradigm.
An undergraduate course has 70 classes (14wk x 5d). A student can be present, or
absent in any of the days. Devise a way to keep track of the attendance of a
student.
- The student can be marked present or absent on day n
- The total number of present/absent has to be calculated
- Check if the student is dis-collegiate (<75%)
- Check if the student is non-collegiate (<90% & > 75%)
*/

#include <bits/stdc++.h>
using namespace std;

class Attendance
{
    int *p;
    int len;

public:
    Attendance(int n)
    {
        len = n;
        p = new int[n];
    }
    ~Attendance()
    {
        delete[] p;
    }
    void initAttendance(int *ara)
    {
        for (int i = 0; i < len; i++)
        {
            p[i] = ara[i];
        }
    }
    void printAttendance()
    {
        for (int i = 0; i < len; i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    int totalPresent()
    {
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += p[i];
        }
        return sum;
    }
    int totalAbsent()
    {
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += !p[i];
        }
        return sum;
    }
    bool isDisCollegiate()
    {
        return totalPresent() < 0.75 * len;
    }
    bool isNonCollegiate()
    {
        return totalPresent() > 0.75 * len && totalPresent() < 0.9 * len;
    }
};

int main()
{
    int ara[] = {1, 1, 1, 1, 1};
    Attendance a(5);
    a.initAttendance(ara);
    a.printAttendance();
    cout << a.totalPresent() << endl;
    cout << a.totalAbsent() << endl;
    cout << a.isDisCollegiate() << endl;
    cout << a.isNonCollegiate() << endl;
    return 0;
}