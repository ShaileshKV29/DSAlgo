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
    cout << llist.count_nodes() << endl;
    cout << llist.sum_nodes() << endl;
    cout << llist.max() << endl;
    Node *p = llist.search(7);
    cout << p->data << " " << p << endl;

    return 0;
}