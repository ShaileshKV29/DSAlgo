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

        // I will come back to this topic
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

        int postfix_evaluation(string postfix)
        {
            int r = 0, x1,x2;
            for(int i = 0; postfix[i] != '\0'; i++)
            {
                if(postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '*' && postfix[i] != '/')
                    this->push(postfix[i]);
                else
                {
                    x2 = (int)pop();
                    x1 = (int)pop();
                    if(x2 >= 48)
                        x2 -= 48;
                    if(x1 >= 48)
                        x1 -= 48;
                    if(postfix[i] == '+')
                        r = x1 + x2;
                    else if(postfix[i] == '-')
                        r = x1 - x2;
                    else if(postfix[i] == '*')
                        r = x1 * x2;
                    else if(postfix[i] == '/')
                        r = x1 / x2;
                    // cout << x1 << postfix[i] << x2 << endl;
                    this->push(r);
                }
            }

            return s[0];
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
    string infix = "3*5+6/2-4";

    Stack st(infix.size());
    string postfix = st.infix_to_postfix(infix);
    int eval = st.postfix_evaluation(postfix);

    // st.display();
    cout << eval << endl;

    // cout << (int)'~';


    return 0;
}