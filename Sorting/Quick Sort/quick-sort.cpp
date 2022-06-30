#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partitioning(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l + 1, j = h;
    while(i < j)
    {
        while(arr[i] <= pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}

void QuickSort(int arr[], int l, int h)
{
    if(l < h)
    {
        int j = partitioning(arr, l, h);

        QuickSort(arr, l, j - 1);
        QuickSort(arr, j+1, h);
    }
}

void display(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[8] = {5,7,10,2,8,15,19,4};
    QuickSort(arr, 0, 7);
    display(arr, 8);

    return 0;
}