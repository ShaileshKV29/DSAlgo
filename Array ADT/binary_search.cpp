#include <iostream>
using namespace std;

int binary_search(int key, int arr[])
{
    int l = 0, h = 10, mid;
    mid = (l+h)/2;
    while(l <= h)
    {
        mid = (l+h)/2;
        if(key == arr[mid])
            return mid;
        else if(key > arr[mid])
            l = mid + 1;
        else if(key < arr[mid])
            h = mid - 1;
    }

    return -1;
}

int main()
{
    int A[10] = {1,2,3,4,5,6,7,8,9,10};
    int index;
    index = binary_search(12, A);
    cout << index << endl;
    
    return 0;
}