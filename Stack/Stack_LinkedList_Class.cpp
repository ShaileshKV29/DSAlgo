#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

class StackLinkedList
{
    Node *Top = nullptr;
    int size = 0;

    public:

        StackLinkedList(int x)
        {
            Node *t = new Node;
            if(t == nullptr)
                cout << "Stack Overflow";
            else
            {
                t->data = x;
                t->next = Top;
                Top = t;
                this->size++;
            }
        }

        void push(int x)
        {
            Node *t = new Node;
            if(t == nullptr)
                cout << "Stack Overflow";
            else
            {
                t->data = x;
                t->next = Top;
                Top = t;
                this->size++;
            }
        }

        int pop()
        {
            int x = -1;
            if(Top == nullptr)
                cout << "Stack is Empty" << endl;
            else
            {
                Node *p = Top;
                Top = Top->next;
                x = p->data;
                delete p;
                this->size--;
            }

            return x;
        }

        int peek(int pos)
        {
            if(pos > 0 && pos <= this->size)
            {
                Node *p = Top;
                for(int i = 0; p != nullptr && i < pos - 1; i++)
                    p = p->next;
                
                if(p != nullptr)
                    return p->data;
            }

            return -1;
        }

        int stackTop()
        {
            if(Top)
                return Top->data;
            return -1;
        }

        int isEmpty()
        {
            return Top ? 0 : 1;
        }

        int isFull()
        {
            Node *t = new Node;
            int r = t ? 1 : 0;
            free(t);
            return r;
        }

        void display()
        {
            Node *p = Top;
            while(p != nullptr)
            {
                cout << p->data << endl;
                p = p->next;
            }
        }
};

int main()
{
    StackLinkedList st(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    // st.display();
    cout << st.stackTop() << endl;
    cout << st.isEmpty() << endl;
    cout << st.isFull() << endl;

    return 0;
}