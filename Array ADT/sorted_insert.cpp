#include <iostream>
using namespace std;

struct Array
{
    int A[15];
    int length;
    int size;
};

void sorted_insert(struct Array *arr, int e)
{
    int i;
    for(i = arr->length - 1; i >= 0; i--)
    {
        if(e < arr->A[i])
            arr->A[i+1] = arr->A[i];
        else{
            arr->A[i+1] = e;
            arr->length++;
            break;
        }
    }

}

int main()
{
    struct Array arr = {{1,3,5,7,9,11,13,15,17,19}, 10, 15};
    for(int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
    cout << endl << endl;
    sorted_insert(&arr, 14);
    cout << "Sorted Insert in Array" << endl;
    for(int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
    
    return 0;
}