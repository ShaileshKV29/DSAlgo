#include<iostream>
using namespace std;

double e(double x, double n)
{
    static double s = 1;
    if(n == 0)
    {
        return s;
    }else
    {
        s = 1 + x/n + s;
        return s;
    }
}

int main()
{
    cout << e(1, 10);

    return 0;
}