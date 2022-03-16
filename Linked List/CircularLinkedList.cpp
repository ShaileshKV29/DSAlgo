#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

class CircularLinkedList
{
    private:
        Node *head;
        int length;

    public:
        CircularLinkedList()
        {
            this->head = nullptr;
            this->length = 0;
        }

        CircularLinkedList(int A[], int n)
        {
            Node *q;
            Node *p = new Node;
            p->data = A[0];
            p->next = nullptr;
            this->head = p;

            for(int i = 1; i < n; i++)
            {
                q = new Node;
                q->data = A[i];
                q->next = nullptr;
                p->next = q;
                p = q;
            }

            q->next = this->head;
            this->length = n;
        }

        void display()
        {
            Node *p = this->head;
            do{
                cout << p->data << " ";
                p = p->next;
            }
            while(p != head);
        }
};

int main()
{
    int A[5] = {1,2,3,4,5};
    CircularLinkedList clist(A, 5);
    clist.display();

    return 0;
}