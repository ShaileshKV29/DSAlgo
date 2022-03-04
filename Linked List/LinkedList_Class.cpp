#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class LinkedList
{
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
        }
};

int main()
{
    

    return 0;
}