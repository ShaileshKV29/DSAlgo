#include <stdio.h>

int main()
{
    int arr[50];
    int size;

    size = sizeof(arr)/sizeof(int);
    printf("Size of array is : %d", size);

    return 0;
}