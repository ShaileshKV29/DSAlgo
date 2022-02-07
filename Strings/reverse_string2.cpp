#include<iostream>
using namespace std;

int main()
{
    char A[] = "python";
    char temp;
    int i, j;

    for(j = 0; A[j] != '\0'; j++)
        continue;

    j = j-1;
    for(i = 0; i < j; i++, j--)
    {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    cout << A;

    return 0;
}