#include<iostream>
using namespace std;

template <class T>
class Stack
{
    private:
        int size;
        int Top;
        T *s;
    
    public:
        Stack()
        {
            size = 0;
            Top = -1;
        }

        Stack(int stack_size)
        {
            size = stack_size;
            Top = -1;
            s = new T[size];
        }

        Stack(T arr[])
        {
            this->size = sizeof(arr)/sizeof(arr[0]);
            s = new T[size];
            Top = -1;

            for(int i = 0; i < size; i++)
                s[i] = arr[i];
            
            Top = size - 1;
        }

        int isEmpty()
        {
            if(Top == -1)
                return 1;
            else
                return 0;
        }

        int isFull()
        {
            if(Top == size - 1)
                return 1;
            else
                return 0;
        }

        void push(T x)
        {
            if(this->isFull())
                cout << "Stack Overflow";
            else
            {
                Top++; 
                s[Top] = x;
            }
        }

        T pop()
        {
            T x = -1;
            if(this->isEmpty())
                cout << "Stack is Empty";
            else
            {
                x = s[Top];
                s[Top] = 0;
                Top--;
            }

            return x;
        }

        T peek(int pos)
        {
            if(this->isEmpty())
            {
                cout << "Stack is Empty";
                return -1;
            }

            if(pos < 0 || pos >= size)
            {
                cout << "Invalid Position";
                return -1;
            }
            else
            {
                int index = Top - pos + 1;
                T x = s[index];
                return x;
            }
        }

        T stackTop()
        {
            if(this->isEmpty())
                cout << "Stack is Empty";
            else
                return s[Top];
            
            return -1;
        }
};

int main()
{
    

    return 0;
}