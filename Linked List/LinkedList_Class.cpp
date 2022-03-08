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
    Node *last = nullptr;

    public:

        LinkedList()
        {
            this->n = 0;
        }

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

        void insert(int key, int pos)
        {
            Node * t = new Node;
            t->data = key;
            t->next = nullptr;
            if(pos == 0)
            {
                t->next = first;
                first = t;
                this->n++;
            }
            else if(pos > 0)
            {
                Node *p = first;
                for(int i = 0; i < pos - 1; i++)
                    p = p->next;

                t->next = p->next;
                p->next = t;
                this->n++;
            }
        }

        void insertLast(int key)
        {
            Node *p = new Node;
            p->data = key;
            p->next = nullptr;
            if(first == nullptr)
            {
                first = p;
                last = first;
            }
            else if(first == last)
            {
                first->next = p;
                last = p;
            }
            else
            {
                last->next = p;
                last = p;
            }
        }

        void insertSorted(int key)
        {
            Node *t = new Node;
            Node *p = first;
            Node *q = nullptr;
            t->data = key;
            t->next = nullptr;

            if(first == nullptr)
            {
                first = t;
                this->n++;
            }
            else
            {
                while(p->data < key)
                {
                    q = p;
                    p = p->next;
                }
                if(p == first)
                {
                    t->next = first;
                    first = t;
                }
                else
                {
                    t->next = q->next;
                    q->next = t;
                    this->n++;
                }
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

        // void display_recursive()
        // {
        //     if(first != nullptr)
        //     {
        //         cout << first->data << " ";
        //         display_recursive();
        //     }
        // }

        int count_nodes()
        {
            Node *p = first;
            int count = 0;
            while(p != nullptr)
            {
                count++;
                p = p->next;
            }
            return count;
        }

        int sum_nodes()
        {
            Node *p = first;
            int sum = 0;
            while(p != nullptr)
            {
                sum += p->data;
                p = p->next;
            }
            return sum;
        }
        
        int max()
        {
            Node *p = first;
            int max = INT32_MIN;
            while(p != nullptr)
            {
                if(p->data > max)
                    max = p->data;
                p = p->next;
            }
            return max;
        }

        Node * search(int key)
        {
            Node *p = first;
            while(p != nullptr)
            {
                if(key == p->data)
                    return p;
                p = p->next;
            }
            return nullptr;
        }
};

int main()
{
    int A[5] = {1,3,5,7,9};
    LinkedList llist(A, 5);
    llist.display();
    llist.insert(6, 3);
    llist.display();

    LinkedList elist;
    elist.insertLast(10);
    elist.insertLast(20);
    elist.insertLast(30);
    elist.insertLast(40);
    elist.insertLast(50);
    elist.display();
    elist.insertSorted(35);
    elist.insertSorted(5);
    elist.display();

    return 0;
}