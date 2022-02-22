#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};


int main()
{
    struct Node n1,n2,n3,n4,n5;
    n1.data = 10;
    n1.next = &n2;    
    n2.data = 20;
    n2.next = &n3;    
    n3.data = 30;
    n3.next = &n4;    
    n4.data = 40;  
    n4.next = &n5;  
    n5.data = 50;
    n5.next = nullptr;

    struct Node *first = &n1;
    cout << first->next;    

    return 0;
}