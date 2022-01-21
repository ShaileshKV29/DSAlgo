#include <iostream>
using namespace std;

void left_shift(int a[])
{
    int i = 0;
    for(i = 0; i < 9; i++ )
    {
        a[i] = a[i+1];
    }
    a[8] = 0;

}

int main()
{
    int A[9] = {1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < 9; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    left_shift(A);

    for(int i = 0; i < 9; i++)
    {
        cout << A[i] << " ";
    }
    
    return 0;
}