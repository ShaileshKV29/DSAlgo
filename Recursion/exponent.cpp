#include<iostream>
using namespace std;

int exponent(int m, int n)
{
    if(n == 0)
        return 1;
    else
        return exponent(m, n - 1) * m;
}

int pow(int m, int n)
{
    if(n == 0)
        return 1;
    else if(n%2 == 0)
        return pow(m*m, n/2);
    else
        return pow(m*m, (n-1)/2) * m;
}

int main()
{
    cout << exponent(2, 5) << endl;    
    cout << exponent(2, 9) << endl;    

    return 0;
}