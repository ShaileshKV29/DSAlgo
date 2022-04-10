#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void enqueue(struct Queue *q, int x)
{
    if(q->rear == q->size - 1)
        printf("Queue is Empty");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if(q->front == q->rear)
        printf("Queue is Empty");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }

    return x;
}

void display(struct Queue q)
{
    for(int i = q.front + 1; i <= q.rear; i++)
    {
        printf("%d ", q.Q[i]);
    }
}

void main()
{
    struct Queue q;
    printf("Enter Size of Queue: ");
    scanf("%d", &q.size);

    q.Q = (int *)malloc(q.size * sizeof(int));
    q.front = q.rear = -1;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    int y = dequeue(&q);

    display(q);
    printf("\n%d", y);
}