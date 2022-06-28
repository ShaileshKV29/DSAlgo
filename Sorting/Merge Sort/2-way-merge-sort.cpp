#include<iostream>
#include<cmath>
using namespace std;

class Sorting
{
    int n;
    int *arr;

    public:
        Sorting()
        {
            n = 0;
        }

        Sorting(int arr2[], int n)
        {
            this->n = n;
            arr = new int[this->n];
            for(int i = 0; i < n; i++)
            {
                this->arr[i] = arr2[i];
            }
        }

        void mergeSort_2_way()
        {
            int B[n] = {0};
            int itr = log2(n) + 1;
            int merge_size = 0;
            for(int k = 0; k < itr; k++)
            {
                for(int i = 0; i < n; i += merge_size)
                {
                    
                }
                merge_size += 2;
            }
        }

        int * merge(int A[], int B[], int m, int n)
        {
            int i,j,k;
            int C[m+n] = {0};
            i = j = k = 0;
            while(i < m && j < n)
            {
                if(A[i] < B[j])
                    C[k++] = A[i++];
                else
                    C[k++] = B[j++];
            }

            for(; i < m; i++)
                C[k++] = A[i];

            for(; j < n; j++)
                C[k++] = B[j];

            return C;
        }

        void display()
        {
            for(int i = 0; i < this->n; i++)
                cout << this->arr[i] << " ";
            cout << endl;
        }

};

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    Sorting mergeSort(arr, 10);
    mergeSort.display();

    return 0;
}