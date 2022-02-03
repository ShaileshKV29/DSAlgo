#include<iostream>
using namespace std;

int main()
{
    int A[10] = {1,2,3,4,5,6,7,8,9,10};
    int k = 10; // Sum
    int key;
    for(int i = 0; i < 9; i++)
    {
        key = k - A[i];
        for(int j = i+1; j < 10; j++)
        {
            if(A[j] == key)
                printf("(%d, %d)\n", A[i], A[j]);
        }
    }

    return 0;
}