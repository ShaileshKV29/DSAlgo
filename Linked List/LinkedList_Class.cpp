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

        Node * get_head()
        {
            return this->first;
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

        void concatinate(LinkedList l)
        {
            Node *p = first;
            while(p->next != nullptr)
            {
                p = p->next;
            }

            p->next = l.get_head();
        }

        void merge(LinkedList l)
        {
            Node *f = this->first;
            Node *s = l.get_head();
            Node *last = nullptr;

            if(f->data < s->data)
            {
                this->first = last = f;
                f = f->next;
                last->next = nullptr;
            }
            else
            {
                this->first = last = s;
                s = s->next;
                last->next = nullptr;
            }

            while(f != nullptr && s != nullptr)
            {
                if(f->data < s->data)
                {
                    last->next = f;
                    last = f;
                    f = f->next;
                    last->next = nullptr;
                }
                else
                {
                    last->next = s;
                    last = s;
                    s = s->next;
                    last->next = nullptr;
                }
            }

            if(f != nullptr)
                last->next = f;
            else
                last->next = s;
        }

        int isLoop()
        {
            Node *p, *q;
            p = q = this->first;
            do
            {
                p = p->next;
                q = q->next;
                q = q != nullptr ? q->next : nullptr;

                if(p == q)
                    return true;
            }while(p && q);

            return false;
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

        void reverse_using_array()
        {
            Node *p = first;
            int A[this->n];
            int i = 0;
            while(p != nullptr)
            {
                A[i] = p->data;
                p = p->next;
                i++;
            }

            p = first;
            i--;
            while(p != nullptr)
            {
                p->data = A[i];
                p = p->next;
                i--;
            }
        }

        void reverse_using_sliding_pointers()
        {
            Node *p, *q, *r;
            p = this->first;
            q = r = nullptr;

            while(p != nullptr)
            {
                r = q;
                q = p;
                p = p->next;
                q->next = r;
            }
            first = q;
        }

        void reverse_revursive(Node *q, Node *p)
        {
            if(p)
            {
                this->reverse_revursive(p, p->next);
                p->next = q;
            }
            else
            {
                this->first = q;
            }
        }

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

        bool checkSorted()
        {
            Node *p = first;
            int x = INT32_MIN;

            while(p != nullptr)
            {
                if(p->data < x)
                    return false;
                
                x = p->data;
                p = p->next;
            }
            return true;
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

        void removeDuplicates()
        {
            Node *p = first;
            Node *q = first->next;

            while(q != nullptr)
            {
                if(p->data != q->data)
                {
                    p = q;
                    q = q->next;
                }
                else
                {
                    p->next = q->next;
                    delete q;
                    q = p->next;
                }
            }
        }

        ~LinkedList()
        {
            Node *p = first;
            Node *q = nullptr;

            while(p != nullptr)
            {
                q = p;
                p = p->next;
                delete q;
            }
        }
};

int main()
{
    int A[5] = {4,5,15,25,31};
    LinkedList alist(A, 5);

    LinkedList elist;
    elist.insertLast(10);
    elist.insertLast(20);
    elist.insertLast(30);
    elist.insertLast(40);
    elist.insertLast(50);
    elist.insertSorted(32);
    elist.insertSorted(34);

    alist.display();
    elist.display();

    elist.merge(alist);
    elist.display();

    cout << elist.isLoop();

    return 0;
}