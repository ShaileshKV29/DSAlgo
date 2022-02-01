#include<iostream>
using namespace std;

int main()
{
    // For Single Element
    int A[10] = {1,2,3,4,5,7,8,9,10,11};
    int sum = 0;
    for(int i = 0; i < 10; i++)
        sum += A[i];

    int s = (A[9]*(A[9] + 1))/2;
    cout << "Missing Element is " << s - sum << endl;

    // For multiple Elements
    int B[10] = {1,2,3,4,7,8,11,12,13,14};
    int diff = B[0] - 0;
    for(int i = 0; i < 10; i++)
    {
        if(diff != B[i] - i)
        {
            while(diff < B[i] - i)
            {
                cout << "Missing Element : " << i+diff << endl;
                diff++;
            }
        }
    }

    return 0;
}