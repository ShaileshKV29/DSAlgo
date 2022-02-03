#include<iostream>
using namespace std;

int main()
{
    int A[10] = {1,2,3,4,5,6,7,8,9,10};
    int k = 10; // Sum
    int i = 0, j = 9;
    while(i < j)
    {
        if(A[i] + A[j] == k){
            printf("(%d, %d)\n", A[i], A[j]);
            i++; j--;
        }
        else if(A[i] + A[j] < k)
            i++;
        else
            j--;
    }

    return 0;
}