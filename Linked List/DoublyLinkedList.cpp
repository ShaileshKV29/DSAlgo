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

        void insert(int pos, int data)
        {
            if(pos < 0 || pos > this->length)
                return;

            Node *t = new Node;
            t->data = data;
            t->prev = nullptr;
            t->next = nullptr;

            if(pos == 0)
            {
                if(this->first == nullptr)
                    this->first = t;
                else
                {
                    t->next = this->first;
                    first->prev = t;
                    first = t;
                }
                this->length++;
            }
            else
            {
                Node *p = this->first;
                for(int i = 1; i < pos; i++)
                    p = p->next;
                
                t->prev = p;
                t->next = p->next;
                p->next = t;
                if(t->next)
                    t->next->prev = t;
                
                this->length++;
            }
        }

        int deleteNode(int node)
        {
            int x;
            if(node == 1)
            {
                if(first == nullptr)
                    return 0;
                else
                {
                    Node *p = first;
                    x = p->data;
                    first = first->next;
                    delete p;
                    if(first)
                        first->prev = nullptr;
                    this->length--;
                }
            }
            else
            {
                Node *p = first;
                for(int i = 1; i < node; i++)
                    p = p->next;
                
                p->prev->next = p->next;
                if(p->next)
                    p->next->prev = p->prev;
                x = p->data;
                delete p;
                this->length--;
            }
            return x;
        }

        void reverse_list()
        {
            Node *p = first;
            Node *temp;
            while (p != nullptr)
            {
                temp = p->next;
                p->next = p->prev;
                p->prev = temp;
                p = p->prev;
                if(p != nullptr && p->next == nullptr)
                    first = p;
            }
            
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
    dlist.insert(3, 22);
    dlist.display();
    dlist.reverse_list();
    dlist.display();

    return 0;
}