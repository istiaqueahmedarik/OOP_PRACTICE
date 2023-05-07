#include <bits/stdc++.h>
using namespace std;

class Train;
class BUS
{
protected:
    float velocity;
    float cost_per_km;

public:
    BUS()
    {
        velocity = 0;
        cost_per_km = 0;
    }
    BUS(float velocity, float cost_per_km)
    {
        this->velocity = velocity;
        this->cost_per_km = cost_per_km;
    }
    friend int time(BUS, Train, float);
    friend int cost(BUS, Train, float);
};
class Train : public BUS
{
public:
    Train(float velocity, float cost_per_km) : BUS(velocity, cost_per_km)
    {
    }
};

int time(BUS b, Train t, float km)
{
    float time_bus = km / b.velocity;
    float time_train = km / t.velocity;
    if (time_bus < time_train)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int cost(BUS b, Train t, float km)
{
    float cost_bus = km * b.cost_per_km;
    float cost_train = km * t.cost_per_km;
    if (cost_bus < cost_train)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    float km, velocity, cost_per_km;
    cin >> km >> velocity >> cost_per_km;
    BUS b(velocity, cost_per_km);
    cin >> velocity >> cost_per_km;
    Train t(velocity, cost_per_km);
    cout << time(b, t, km) << endl;
    cout << cost(b, t, km) << endl;
    return 0;
}