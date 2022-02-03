#include<iostream>
using namespace std;

int main()
{
    int A[10] = {1,-1,3,4,5,9896,7,8,9,10};
    int max, min;
    max = min = A[0];
    for(int i = 1; i < 10; i++)
    {
        if(A[i] < min)
            min = A[i];
        else if(A[i] > max)
            max = A[i];
    }

    cout << "Max: " << max << "\nMin:" << min << endl;

    return 0;
}