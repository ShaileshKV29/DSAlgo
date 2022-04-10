#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void main()
{
    struct Queue q;
    printf("Enter Size of Queue: ");
    scanf("%d", &q.size);

    q.Q = (int *)malloc(q.size * sizeof(int));
    q.front = q.rear = -1;
}