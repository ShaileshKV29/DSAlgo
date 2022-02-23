#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first = nullptr;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = nullptr;
    last = first;
    for(int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while(p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void display_r(struct Node *p)
{
    if(p != nullptr)
    {
        cout << p->data << " ";
        display_r(p->next);
    }
}

int main()
{
    int A[5] = {23,244,3245,523,1};
    create(A, 5);
    display(first);
    cout << endl;
    display_r(first);

    return 0;
}