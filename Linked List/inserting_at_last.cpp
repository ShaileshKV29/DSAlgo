#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first = nullptr, *last = nullptr;

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

void insert(int x, int pos)
{
    Node *k, *p;
    if(pos == 0)
    {
        k = new Node;
        k->data = x;
        k->next = first;
        first = k;
    }
    else if(pos > 0)
    {
        p = first;
        for(int i = 0; i < pos - 1; i++)
            p = p->next;
        
        if(p)
        {
            k = new Node;
            k->data = x;
            k->next = p->next;
            p->next = k;
        }
    }
}

void insertLast(int x)
{
    Node *t = new Node;
    t->data = x;
    t->next = nullptr;

    if(first == nullptr)
        first = last = t;
    else
    {
        last->next = t;
        last = t;
    }
}

void SortedInsert(Node *p, int x)
{
    Node *t, *q = nullptr;
    t = new Node;
    t->data = x;
    t->next = nullptr;

    if(first == nullptr)
        first = t;
    else
    {
        while(p && p->data < x)
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
        }
    }
}

void display(Node *p)
{
    while(p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void display_r(Node *p)
{
    if(p != nullptr)
    {
        cout << p->data << " ";
        display_r(p->next);
    }
}

int countNodes(Node *p)
{
    int count = 0;
    while(p != nullptr)
    {
        count++;
        p = p->next;
    }
    
    return count;
}

int sum(Node *p)
{
    int sum = 0;
    while(p != nullptr)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int sum_r(Node *p)
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

Node * search_improved(Node *p, int key)
{
    Node *q = nullptr;
    while(p != nullptr)
    {
        if(p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }

    return nullptr;
}

int main()
{
    SortedInsert(first, 35);
    SortedInsert(first, 25);
    SortedInsert(first, 45);
    SortedInsert(first, 0);
    SortedInsert(first, 50);
    display(first);

    return 0;
}