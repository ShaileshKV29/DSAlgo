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

        void insert(int pos, int x)
        {
            Node *t = new Node;
            t->data = x;
            int i;

            if(pos == 0)
            {
                if(head == nullptr)
                {
                    head = t;
                    head->next = head;
                }
                else
                {
                    t->next = head;
                    Node *p = head;
                    while(p->next != head)
                        p = p->next;

                    p->next = t;
                }
            }
            else
            {
                Node *p = head;
                for(i = 0; i < pos - 1; i++)
                    p = p->next;

                t->next = p->next;
                p->next = t;
            }

            this->length++;
        }

        void display()
        {
            Node *p = this->head;
            do{
                cout << p->data << " ";
                p = p->next;
            }
            while(p != head);

            cout << endl;
        }
};

int main()
{
    int A[5] = {1,2,3,4,5};
    CircularLinkedList clist(A, 5);
    clist.display();
    clist.insert(9, 10);
    clist.display();

    return 0;
}