#include<iostream>
using namespace std;

int fact(int n)
{
    if(n == 0)
        return 1;
    else
        return fact(n - 1) * n;
}

int pow(int x, int n)
{
    if(n == 0)
        return 1;
    else if(n%2 == 0)
        return pow(x*x, n/2);
    else
        return pow(x*x, (n-1)/2) * x;
}

int taylor_series(int x, int n)
{
    if(n == 0)
        return 1;
    else
        return taylor_series(x, n - 1) + (pow(x, n)/fact(n));
}

int taylor_series_better(int x, int n)
{
    static int pow = 1;
    static int fact = 1;
    int r;

    if(n == 0)
        return 1;
    else
        r = taylor_series(x, n - 1);
        pow *= x;
        fact *= n;
        return r + pow/fact;
}

int main()
{
    cout << taylor_series_better(5, 3);

    return 0;
}