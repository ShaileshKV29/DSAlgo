#include<iostream>
using namespace std;

int main()
{
    int arr[8] = {5,4,1,4,3,5,1,2};
    int res = 0;
    for(int i = 0; i < 8; i++)
    {
        res ^= arr[i];
    }
    int temp = res;
    int temp2 = res;
    int index = 0;
    while(temp > 0)
    {
        if((temp & 1) == 1)
            break;
        index++;
        temp = temp >> 1;
    }
    int mask = 1;
    mask = mask << index;
    for(int i = 0; i < 8; i++)
    {
        if((arr[i] & mask) == 1)
            res ^= arr[i];
    }

    cout << res << endl;
    cout << (res^temp2) << endl;

    return 0;
}