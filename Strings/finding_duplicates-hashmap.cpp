#include<iostream>
using namespace std;

int main()
{
    char A[] = "zoopz";
    int H[26] = {0};
    int i = 0;
    int index;
    while(A[i] != '\0')
    {
        index = A[i] - 97;
        H[index]++;
        i++;
    }

    for(int j = 0; j < 26; j++)
    {
        if(H[j] > 1)
            cout << (char)(97+j) << " ";
    }

    return 0;
}