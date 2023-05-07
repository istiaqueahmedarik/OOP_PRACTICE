#include <bits/stdc++.h>
using namespace std;

class SSC
{
protected:
    int roll;
    int primaryMarks;

public:
    SSC(int roll, int primaryMarks)
    {
        this->roll = roll;
        this->primaryMarks = primaryMarks;
    }
    void setRoll(int roll)
    {
        this->roll = roll;
    }
    void setPrimaryMarks(int primaryMarks)
    {
        this->primaryMarks = primaryMarks;
    }
    int getRoll()
    {
        return roll;
    }
    int getPrimaryMarks()
    {
        return primaryMarks;
    }
};

class Science : public SSC
{
    int scienceMarks;

public:
    Science(int roll, int primaryMarks, int scienceMarks) : SSC(roll, primaryMarks)
    {
        this->scienceMarks = scienceMarks;
    }
    void setScienceMarks(int scienceMarks)
    {
        this->scienceMarks = scienceMarks;
    }
    int getScienceMarks()
    {
        return scienceMarks;
    }
};

class Commerce : public SSC
{
    int commerceMarks;

public:
    Commerce(int roll, int primaryMarks, int commerceMarks) : SSC(roll, primaryMarks)
    {
        this->commerceMarks = commerceMarks;
    }
    void setCommerceMarks(int commerceMarks)
    {
        this->commerceMarks = commerceMarks;
    }
    int getCommerceMarks()
    {
        return commerceMarks;
    }
};

int compare(Science s, Commerce c)
{
    if ((s.getPrimaryMarks() + s.getScienceMarks()) / 2 > (c.getPrimaryMarks() + c.getCommerceMarks()) / 2)
    {
        return s.getRoll();
    }
    else
    {
        return c.getRoll();
    }
}

int main()
{
    Science s(1, 80, 90);
    Commerce c(2, 70, 80);
    cout << compare(s, c) << endl;
    return 0;
}