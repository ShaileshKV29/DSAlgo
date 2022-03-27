#include<iostream>
using namespace std;

class Stack
{
    public:
        int size;
        int Top;
        int *s;

        Stack(int size)
        {
            this->size = size;
            this->s = new int[this->size];
            this->Top = -1;
        }

        Stack(int size, int A[])
        {
            this->size = size;
            this->s = new int[this->size];
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

        void push(int x)
        {
            if(this->isFull())
                printf("Stack Overflow");
            else
            {
                this->Top++;
                this->s[this->Top] = x;
            }
        }

        int pop()
        {
            if(this->isEmpty())
                return -1;
            else
            {
                int x = s[Top];
                s[Top] = 0;
                Top--;

                return x;
            }
        }
};

int main()
{
    // int A[5] = {1,2,3,4,5};
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    int deletedElement = st.pop();
    cout << deletedElement;

    return 0;
}