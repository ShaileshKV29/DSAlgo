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

int countNodes(struct Node *p)
{
    int count = 0;
    while(p != nullptr)
    {
        count++;
        p = p->next;
    }
    
    return count;
}

int sum(struct Node *p)
{
    int sum = 0;
    while(p != nullptr)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int sum_r(struct Node *p)
{
    if(p == nullptr)
        return 0;
    else
        return sum_r(p->next) + p->data;
}

int max(Node *p)
{
    int max = INT32_MIN;
    while(p != nullptr)
    {
        if(p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int max_recursive(Node *p)
{
    int x = 0;
    if(p == nullptr)
        return INT32_MIN;

    x = max_recursive(p->next);
    return x > p->data ? x : p->data;
}

Node * linear_search(Node *p, int key)
{
    while(p != nullptr)
    {
        if(key == p->data)
            return p;
        p = p->next;
    }
    return nullptr;
}

int main()
{
    int A[5] = {23,244,3245,523,1};
    create(A, 5);
    display(first);
    cout << endl;
    display_r(first);
    int nodes = countNodes(first);
    cout << endl << nodes << endl;
    cout << sum(first) << endl;
    cout << sum_r(first) << endl;
    cout << max(first) << endl;
    cout << max_recursive(first) << endl;
    cout << linear_search(first, 1) << endl;

    return 0;
}