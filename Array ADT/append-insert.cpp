#include<iostream>
using namespace std;

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    cout << "Elements are : " << endl;
    for(i = 0; i < arr.length; i++)
        cout << arr.A[i] << " ";
}

void Append(struct Array *arr, int element)
{
    if(arr->length < arr->size)
        arr->A[arr->length++] = element;
}

void insert(struct Array *arr, int index, int element)
{
    if(index >= 0 && index <= arr->length)
    {
        for(int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = element;
        arr->length++;
    }
}

int main()
{
    struct Array arr = {{1,2,3,4,5}, 10, 5};
    Append(&arr, 10);
    insert(&arr, 9, 22);
    // Append(&arr, 10);
    // Append(&arr, 10);
    // Append(&arr, 10);
    // Append(&arr, 10);
    // Append(&arr, 11);
    Display(arr);

    return 0;
}