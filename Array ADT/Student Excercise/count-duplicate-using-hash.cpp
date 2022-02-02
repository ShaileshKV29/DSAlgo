#include<iostream>
using namespace std;

int main()
{
    int A[10] = {3,6,8,8,10,12,15,15,15,20};

    int H[21] = {0};

    for(int i = 0; i < 10; i++)
        H[A[i]]++;

    for(int i = 1; i <= 20; i++)
        if(H[i] > 1) cout << "Element: " << i << " Count: " << H[i] << endl;

    return 0;
}