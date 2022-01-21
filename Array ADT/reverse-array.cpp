#include <iostream>
using namespace std;

void reverse_array(int a[])
{
    int i = 0, j = 8, temp;
    for(i = 0; i < j; i++, j--)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

}

int main()
{
    int A[9] = {1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < 9; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    reverse_array(A);

    for(int i = 0; i < 9; i++)
    {
        cout << A[i] << " ";
    }
    
    return 0;
}