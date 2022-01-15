#include<iostream>
using namespace std;

int fib(int n)
{
    static int F[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
    if(n <= 1)
    {
        F[n] = n;
        return n;
    }else
    {
        if(F[n - 1] == -1)
            F[n - 1] = fib(n-1);
        
        if(F[n-2] == -1)
            F[n - 2] = fib(n-2);
        
        return F[n-2] + F[n - 1];
    }
}

int main()
{
    cout << fib(6);

    return 0;
}