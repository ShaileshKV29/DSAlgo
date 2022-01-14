#include<iostream>
using namespace std;

int sum_static(int n, int i = 1)
{
    static int sum = 0;
    if(i <= n)
    {
        sum += i;
        sum_static(n, i + 1);
    }

    return sum;
}

int sum_better(int n)
{
    if(n == 0)
        return 0;
    else
        return sum_better(n - 1) + n;
}

int main()
{
    cout << sum_static(5) << endl;
    cout << sum_better(10) << endl;    

    return 0;
}