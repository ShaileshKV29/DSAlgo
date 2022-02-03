#include<iostream>
using namespace std;

int main()
{
    int A[10] = {2,123,23,123,54,77,8,77,2,2};
    int count;
    for(int i = 0; i < 9; i++)
    {
        count = 1;
        if(A[i] != -1)
        {
            for(int j = i+1; j < 10; j++)
            {
                if(A[i] == A[j]){
                    count++;
                    A[j] = -1;
                }
            }

            if(count > 1)
                printf("Element: %d Count: %d\n", A[i], count);
        }
    }

    return 0;
}