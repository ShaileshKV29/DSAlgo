#include <iostream>
using namespace std;

void array_rotation(int a[])
{
    int i = 0;
    int first = a[0];
    for(i = 0; i < 9; i++ )
    {
        a[i] = a[i+1];
    }
    a[8] = first;

}

void array_rotation_n(int a[], int n)
{
    for(int j = 1; j <= n; j++)
    {
        int i;
        int first = a[0];
        for(i = 0; i < 9; i++ )
        {
            a[i] = a[i+1];
        }
        a[8] = first;
    }

}

int main()
{
    int A[9] = {1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < 9; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl << endl;
    // for (int j = 0; j < 5; j++)
    // {
    //     array_rotation(A);
    // }

    array_rotation_n(A, 1);
    
    // array_rotation(A);

    cout << "Rotated Array" << endl;
    for(int i = 0; i < 9; i++)
    {
        cout << A[i] << " ";
    }
    
    return 0;
}