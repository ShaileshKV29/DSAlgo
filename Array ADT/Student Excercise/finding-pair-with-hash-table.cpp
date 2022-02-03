#include<iostream>
using namespace std;

int main()
{
    int A[10] = {1,2,3,4,5,6,7,8,9,10};
    int H[11] = {0};
    int k = 10; // Sum
    int key;
    for(int i = 0; i < 9; i++)
    {
        key = k - A[i];
        if(H[key] != 0)
            printf("(%d, %d)\n", A[i], key);
        H[A[i]]++;

    }

    return 0;
}