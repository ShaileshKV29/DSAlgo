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
            int Top = -1;
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
            for(int i = this->size - 1; i >= 0; i--)
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
};

int main()
{
    int A[5] = {1,2,3,4,5};
    Stack st(5, A);
    st.display();
    cout << st.isEmpty() << endl;
    cout << st.isFull() << endl;

    return 0;
}