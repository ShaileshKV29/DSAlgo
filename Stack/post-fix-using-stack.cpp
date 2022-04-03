#include<iostream>
using namespace std;

class Stack
{
    private:
        int size;
        int Top;
        char *s;
    
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
            s = new char[size];
        }

        Stack(char arr[])
        {
            this->size = sizeof(arr)/sizeof(arr[0]);
            s = new char[size];
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

        void push(char x)
        {
            if(this->isFull())
                cout << "Stack Overflow";
            else
            {
                Top++; 
                s[Top] = x;
            }
        }

        char pop()
        {
            char x;
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

        char peek(int pos)
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
                char x = s[index];
                return x;
            }
        }

        char stackTop()
        {
                // cout << "Stack is Empty";
            if(this->isEmpty())
                return '0';
            else
                return s[Top];
            
            return '0';
        }

        int parenthesis_matching(string str)
        {
            int str_size = sizeof(str)/sizeof(str[0]);
            this->size = str_size + 1;
            this->s = new char[str_size + 1];
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

        int isOperand(char x)
        {
            if(x == '+' || x == '-' || x == '*' || x == '/')
                return 0;
            else 
                return 1;
        }

        int precedence(char x)
        {
            if(x == '+' || x == '-')
                return 1;
            else if(x == '*' || x == '/')
                return 2;

            return 0;
        }

        string infix_to_postfix(string exp)
        {
            string postfix = "";
            int i = 0;
            while(exp[i] != '\0')
            {
                if(this->isOperand(exp[i]))
                    postfix += exp[i++];
                else
                {
                    if(precedence(exp[i]) > precedence(stackTop()))
                        push(exp[i++]);
                    else 
                        postfix += pop();
                }
            }
            
            while(!isEmpty())
                postfix += pop();

            return postfix;
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
    string infix = "a+b*c-d/e";

    Stack st(infix.size());
    string postfix = st.infix_to_postfix(infix);
    cout << postfix;

    return 0;
}