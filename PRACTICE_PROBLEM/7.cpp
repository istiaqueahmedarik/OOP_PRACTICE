
#include <bits/stdc++.h>
using namespace std;
class Val
{
    int n;

public:
    Val(int n)
    {
        this->n = n;
    }
    Val()
    {
        n = 0;
    }
    int square_sum()
    {
        int sm = 0;
        for (int i = 0; i < n; i++)
        {
            sm += (i + 1) * (i + 1);
        }
        return sm;
    }
    int cube_sum()
    {
        int sm = 0;
        for (int i = 0; i < n; i++)
        {
            sm += (i + 1) * (i + 1) * (i + 1);
        }
        return sm;
    }
    int sum()
    {
        int sm = 0;
        for (int i = 0; i < n; i++)
        {
            sm += (i + 1);
        }
        return sm;
    }
};
int main()
{
    int n;
    cin >> n;
    Val v(n);
    cout << v.square_sum() << endl;
    cout << v.cube_sum() << endl;
    cout << v.sum() << endl;
}