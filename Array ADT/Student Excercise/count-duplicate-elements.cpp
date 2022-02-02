#include<iostream>
using namespace std;

int main()
{
    int A[10] = {3,6,8,8,10,12,15,15,15,20};
    int lastDuplicate = 0;

    for(int i = 0; i < 10; i++)
    {
        if(A[i] == A[i + 1] && A[i] != lastDuplicate)
        {
            int j = i+1;
            while(A[j] == A[i])
                j++;

            cout << "Count of " << A[i] << " is " << j-i << endl;
            i = j - 1;
        }
    }

    return 0;
}