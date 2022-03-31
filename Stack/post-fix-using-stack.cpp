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
        }

        void display()
        {
            if(this->isEmpty())
                cout << "Stack is Empty";
            else
            {
                for(int i = Top; i >= 0; i--)
                {
                    cout << s[i] << endl;
                }
            }
        }
};

int main()
{
    char A[5] = {'a', 'b', 'c', 'd', 'e'};

    Stack<char> st(A);
    // st.display();
    cout << st.stackTop() << endl;
    // cout << sizeof(A);
    

    return 0;
}