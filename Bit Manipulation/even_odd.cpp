#include<iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    if((a & 1) == 1)
        cout << "Odd";
    else if((a & 1) == 0)
        cout << "Even";

    return 0;
}