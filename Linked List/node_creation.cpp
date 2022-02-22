#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *p;
    p = new struct Node;
    p->data = 10;
    p->next = nullptr;  
    cout << p->data << endl;
    cout << p->next << endl;

    return 0;
}