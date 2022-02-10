#include<iostream>
using namespace std;

// Important Program

int main()
{
    char A[] = "finding";
    int H = 0, x = 0;

    for(int i = 0; A[i] != '\0'; i++)
    {
        x = 1;
        x = x << (A[i] - 97);
        // printf("%d ", x & H);
        // and = x & H;
        // if(and > 0)
        //     printf("%d ", and);
        if((x & H) > 0)
            printf("%c is Duplicate\n", A[i]);
        else
            H = x | H;
    }
    // printf("%d", H & 32);

    return 0;
}