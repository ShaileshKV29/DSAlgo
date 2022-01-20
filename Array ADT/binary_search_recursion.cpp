#include <iostream>
using namespace std;

int binary_search(int key, int arr[], int l = 0, int h = 10)
{
    int mid;
    mid = (l+h)/2;
    if(l > h)
        return -1;
    else if(key == arr[mid])
        return mid;
    else if(key > arr[mid])
        return binary_search(key, arr, mid+1, h);
    else if(key < arr[mid])
        return binary_search(key, arr, l, mid - 1);
    else
        return -1;
}

int main()
{
    int A[10] = {1,2,3,4,5,6,7,8,9,10};
    int index;
    index = binary_search(10, A);
    cout << index << endl;
    
    return 0;
}