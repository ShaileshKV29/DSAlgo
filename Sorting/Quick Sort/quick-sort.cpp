#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void display(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int partitioning(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l, j = h;
    while(i < j)
    {
        do{
            i++;
        }while(arr[i] <= pivot);

        while(arr[j] > pivot)
        {
            j--;
        }
            
        if(i < j){
            cout << "Swapping: " << arr[i] << " " << arr[j] << endl;
            swap(arr[i], arr[j]);
        }
    }
    display(arr, 8);
    cout << "Partitioning: " << arr[l] << " " << arr[j] << endl;
    swap(arr[l], arr[j]);
    display(arr, 8);
    cout << endl;
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

int main()
{
    int arr[8] = {5,7,10,2,8,15,19,4};
    display(arr, 8);
    QuickSort(arr, 0, 7);
    display(arr, 8);

    return 0;
}