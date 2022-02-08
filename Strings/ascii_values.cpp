#include<iostream>
using namespace std;

int main()
{
    char A = 'A';
    printf("%d\n", A);

    for(int c = 0; c <= 127; c++)
    {
        cout << (char)c << "-" << c << "  ";
        if(c%10 == 0)
            cout << endl << endl;   
    } 

    return 0;
}