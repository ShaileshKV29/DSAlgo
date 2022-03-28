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
    st.display();

    return 0;
}