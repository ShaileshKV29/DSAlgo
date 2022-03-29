#include<iostream>
using namespace std;

template <class T>
class Stack
{
    int size;
    int Top;
    T *s;

    public:

        Stack()
        {
            this->size = 0;
        }

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
            int x = -1;

            if(index < 0 || index > size - 1)
                printf("Invalid Position");
            else
                x = s[index];

            return x;
        }

        T stackTop()
        {
            if(this->isEmpty())
                return -1;
            else
                return s[Top];
        }

        int parenthesis_matching(string str)
        {
            int str_size = sizeof(str)/sizeof(str[0]);
            this->size = str_size + 1;
            this->s = new T[str_size + 1];
            this->Top = -1;
            for(auto x: str)
            {
                if(x == '(' || x == '{' || x == '[')
                    this->push(x);
                else if(x == ')' || x == '}' || x == ']')
                {
                    int k = s[Top];
                    if(x < 50)
                    {
                        if(k + 1 == x)
                            this->pop();
                        else
                            return 0;
                    }
                    else
                    {
                        if(k + 2 == x)
                            this->pop();
                        else
                            return 0;
                    }
                }
            }

            if(this->isEmpty())
                return 1;
            else
                return 0;

        }
};

int main()
{
    // int A[5] = {1,2,3,4,5};
    Stack <char>st;

    // st.push(10);
    int result = st.parenthesis_matching("{[(a+b)*(c-d)]}[]");
    
    if(result)
        cout << "Parenthesis Matched" << endl;
    else
        cout << "Parenthesis did not Match" << endl;

    return 0;
}