#include<iostream>
using namespace std;

struct Array
{
    int A[10];
    int length;
    int size;
};

void merge_array(struct Array *arr1, struct Array *arr2, struct Array *arr)
{
    int i = 0, j = 0, k = 0;
    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            arr->A[k++] = arr1->A[i++];
        else
            arr->A[k++] = arr2->A[j++];
    }

    for(; i < arr1->length; i++)
        arr->A[k++] = arr1->A[i];

    for(; j < arr2->length; j++)
        arr->A[k++] = arr2->A[j];
}

int main()
{
    struct Array arr1 = {{1,3,5,7,9}, 5, 10};
    struct Array arr2 = {{2,4,6,23,42}, 5, 10};
    struct Array arr = {{}, 10, 10};
    merge_array(&arr1, &arr2, &arr);

    for(int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }

    return 0;
}