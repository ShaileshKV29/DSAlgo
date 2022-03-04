#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class LinkedList
{
    int n;
    Node *first = nullptr;

    public:

        LinkedList(int A[], int n)
        {
            Node *t;
            Node *p = new Node;
            p->data = A[0];
            p->next = nullptr;
            first = p;

            for(int i = 1; i < n; i++)
            {
                t = new Node;
                t->data = A[i];
                t->next = nullptr;
                p->next = t;
                p = t;

            } 

            this->n = n;       
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
};

int main()
{
    int A[5] = {1,3,5,7,9};
    LinkedList ll(A, 5);
    ll.display();

    return 0;
}