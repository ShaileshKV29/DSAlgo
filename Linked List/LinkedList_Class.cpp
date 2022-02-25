#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class LinkedList
{
    Node *p;
    Node *first = nullptr;
    public:

        void create(int A[], int n)
        {
            int i;
            struct Node *t, *last;
            first = new Node;
            first->data = A[0];
            first->next = nullptr;
            last = first;
            for (int i = 1; i < n; i++)
            {
                t = new Node;
                t->data = A[i];
                t->next = nullptr;
                last->next = t;
                last = t;
            }
        }

        void insert(int x, int pos)
        {
            Node *k, *p;
            if (pos == 0)
            {
                k = new Node;
                k->data = x;
                k->next = first;
                first = k;
            }
            else if (pos > 0)
            {
                p = first;
                for (int i = 0; i < pos - 1; i++)
                    p = p->next;

                if (p)
                {
                    k = new Node;
                    k->data = x;
                    k->next = p->next;
                    p->next = k;
                }
            }
        }

        void display()
        {
            while (first != nullptr)
            {
                cout << first->data << " ";
                first = first->next;
            }
        }

        void display_r(Node *p)
        {
            if (p != nullptr)
            {
                cout << p->data << " ";
                display_r(p->next);
            }
        }

        int countNodes()
        {
            int count = 0;
            while (first != nullptr)
            {
                count++;
                first = first->next;
            }

            return count;
        }

        int sum()
        {
            int sum = 0;
            while (first != nullptr)
            {
                sum += first->data;
                first = first->next;
            }
            return sum;
        }

        int sum_r(Node *p)
        {
            if (p == nullptr)
                return 0;
            else
                return sum_r(p->next) + p->data;
        }

        int max()
        {
            int max = INT32_MIN;
            while (first != nullptr)
            {
                if (first->data > max)
                    max = first->data;
                first = first->next;
            }
            return max;
        }

        int max_recursive(Node *p)
        {
            int x = 0;
            if (p == nullptr)
                return INT32_MIN;

            x = max_recursive(p->next);
            return x > p->data ? x : p->data;
        }

        Node *linear_search(int key)
        {
            while (first != nullptr)
            {
                if (key == first->data)
                    return first;
                first = first->next;
            }
            return nullptr;
        }

        Node *search_improved(int key)
        {
            Node *q = nullptr;
            while (first != nullptr)
            {
                if (first->data == key)
                {
                    q->next = first->next;
                    first->next = first;
                    first = first;
                    return first;
                }
                q = first;
                first = first->next;
            }

            return nullptr;
        }
};

int main()
{
    int A[5] = {23, 244, 3245, 523, 1};
    LinkedList list;
    list.create(A, 5);
    list.display();
    cout << endl;
    list.insert(15, 0);
    list.display();

    return 0;
}