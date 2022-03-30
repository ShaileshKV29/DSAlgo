#include<iostream>
using namespace std;

template <class T>
class Stack
{
    public:
        int size;
        int Top;
        T *s;

        Stack(int size)
        {
            this->size = size;
            this->s = new T[this->size];
            this->Top = -1;
        }

        Stack(int size, T A[])
        {
            this->size = size;
            this->s = new T[this->size];
            for(int i = 0; i < this->size; i++)
            {
                s[i] = A[i];
            }
            this->Top = this->size - 1;
        }

        void display()
        {
            for(int i = this->Top; i >= 0; i--)
            {
                cout << s[i] << endl;
            }
        }

        bool isEmpty()
        {
            if(this->Top == -1)
                return true;
            else
                return false;
        }

        bool isFull()
        {
            if(this->Top == this->size - 1)
                return true;
            else
                return false;
        }

        void push(T x)
        {
            if(this->isFull())
                printf("Stack Overflow");
            else
            {
                this->Top++;
                this->s[this->Top] = x;
            }
        }

        T pop()
        {
            if(this->isEmpty())
                return -1;
            else
            {
                T x = s[Top];
                s[Top] = 0;
                Top--;

                return x;
            }
        }

        T peek(int pos)
        {
            int index = Top - pos + 1;

            if(index < 0 || index > size - 1)
            {
                printf("Invalid Position");
                return -1;
            }
            else
            {
                T x = s[index];
                return x;
            }
        }

        T stackTop()
        {
            if(this->isEmpty())
                return -1;
            else
                return s[Top];
        }
};

int main()
{
    

    return 0;
}