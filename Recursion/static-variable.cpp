#include<iostream>
using namespace std;

int function(int n)
{
    static int x = 0;
    if(n > 0)
    {
        x++;
        return function(n-1) + x;
    }
    return 0;
}

int main()
{
    cout << function(5) << endl;    

    return 0;
}