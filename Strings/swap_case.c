#include<stdio.h>

int main(int argc, char const *argv[])
{
    char A[10] = "WeLcOme";
    int i = 0;
    while(A[i] != '\0')
    {
        if(A[i] > 95)
            A[i] = A[i] - 32;
        else
            A[i] = A[i] + 32;
        i++;
    }

    printf("%s", A);
    return 0;
}
