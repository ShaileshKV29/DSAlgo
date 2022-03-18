#include<iostream>
using namespace std;

class Node
{
    public:
        Node *prev;
        int data;
        Node *next;
};

class DoublyLinkedList
{
    Node *first;
    Node *last;
    int length;

    public:
        DoublyLinkedList()
        {
            first = nullptr;
            last = nullptr;
            length = 0;
        }

        DoublyLinkedList(int A[], int n)
        {
            Node *p;
            p = new Node;
            p->data = A[0];
            p->prev = nullptr;
            p->next = nullptr;
            first = p;

            for(int i = 1; i < n; i++)
            {
                last = new Node;
                last->data = A[i];
                last->prev = p;
                last->next = nullptr;
                p->next = last;
                p = p->next;
            }

            this->length = n;
        }

        void display()
        {
            Node *p = first;
            while(p != nullptr)
            {
                cout << p->data << " ";
                p = p->next;
            }
            cout << endl;
        }

        void display_reverse()
        {
            Node *p = this->last;
            while(p != nullptr)
            {
                cout << p->data << " ";
                p = p->prev;
            }
            cout << endl;
        }
};

int main()
{
    int A[5] = {5,4,3,2,1};


    DoublyLinkedList dlist(A, 5);
    dlist.display();
    dlist.display_reverse();
    return 0;
}