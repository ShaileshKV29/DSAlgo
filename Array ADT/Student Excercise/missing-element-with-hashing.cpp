#include<iostream>
using namespace std;

class Array
{
    private:
        int *A;
        int length;
        int size;
    
    public:
        Array()
        {
            length = 0;
            size = 10;
            A = new int[size]; 
        }

        Array(int size)
        {
            length = 0;
            this->size = size;
            A = new int[size];
        }

        Array(int size, int element)
        {
            length = size;
            this->size = size;
            A = new int[size] {element};
        }

        void Create(int length)
        {
            for(int i = 0; i < length; i++)
                cin >> A[i];
            this->length = length;
        }

        int * getArray(){return A;}
        int getLength(){return this->length;};

        int max()
        {
            int max = A[0];
            for(int i = 1; i < length; i++)
            {
                if(max < A[i])
                    max = A[i];
            }
            return max;
        }

        void Display()
        {
            for(int i = 0; i < length; i++)
                cout << A[i] << " ";
            cout << endl;

        }

        ~Array()
        {
            delete []A;
        }
};

int main()
{
    Array A(10);
    A.Create(10);
    A.Display();
    int *a = A.getArray();
    Array H(A.max() + 1, 0);
    H.Display();
    int *h = H.getArray();

    for(int i = 0; i < A.getLength(); i++)
        h[a[i]]++;
    
    H.Display();

    for(int i = 1; i < A.max(); i++)
        if(h[i] == 0) cout << i << endl;


    return 0;
}