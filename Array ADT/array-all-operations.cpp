#include<iostream>
using namespace std;

template <class T>
class Array
{
    private:
        T *A;
        int size;
        int length;
    
    public:
        Array()
        {
            size = 10;
            length = 0;
            A = new T[size];
        }

        Array(int size)
        {
            this->size = size;
            length = 0;
            A = new T[size];
        }

        void Display();
        void Insert(int index, T element);
        T Delete(int index);

        ~Array()
        {
            delete []A;
        }
};

template <class T>
void Array<T>::Display()
{
    for(int i = 0; i < length; i++)
        cout << A[i] << " ";

    cout << endl;
}

template <class T>
void Array<T>::Insert(int index, T element)
{
    if(index >= 0 && index <= length)
    {
        for(int i = length - 1; i >= index; i--)
            A[i + 1] = A[i];
        A[index] = element;
        length++;
    }
}

template <class T>
T Array<T>::Delete(int index)
{
    T x;
    if(index >= 0 && index < length)
    {
        x = A[index];
        for(int i = index; i < length-1; i++)
            A[i] = A[i+1];
        length--;
    }

    return x;
}

int main()
{
    Array<int> arr(10);
    arr.Insert(0, 5);
    arr.Insert(1, 15);
    arr.Insert(2, 115);
    arr.Insert(3, 1155);

    arr.Display();

    cout << arr.Delete(2) << endl;
    arr.Display();

    Array<string> arr2(5);
    arr2.Insert(0, "Hello");
    arr2.Insert(1, "World");
    arr2.Insert(2, "C++");

    arr2.Display();
    arr2.Delete(2);
    arr2.Display();

    return 0;
}