#include<iostream>
using namespace std;

int main()
{
    char A[10] = "WELCOME";
    int i = 0;
    while(A[i] != '\0')
    {
        A[i] += 32;
        i++;
    }

    cout << A << endl;

    return 0;
}