#include<iostream>
using namespace std;

// If the recursive call is the last statement inside a recursive function then it is a Tail Recursive Funciton
void function(int n)
{
    if(n>0)
    {
        cout << n << " ";
        function(n - 1);
    }
}

int main()
{
    function(10);

    return 0;
}