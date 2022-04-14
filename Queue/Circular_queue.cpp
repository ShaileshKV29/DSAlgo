#include<iostream>
using namespace std;

class Queue
{
    int size;
    int front;
    int rear;
    int *Q;

    public:

        Queue(int size)
        {
            this->size = size;
            front = rear = -1;
            Q = new int[this->size];
        }

        Queue(int arr[], int size)
        {
            front = -1;
            this->size = size;
            Q = new int[this->size];
            int i;
            for(i = 0; i < this->size; i++)
            {
                Q[i] = arr[i];
            }
            rear = i - 1;
        }

        void enqueue(int x)
        {
            if((rear+1)%size == front)
                cout << "Queue is Full" << endl;
            else
            {
                rear = (rear + 1)%size;
                Q[rear] = x;
            }
        }

        int dequeue()
        {
            int x = -1;
            if(front == rear)
                cout << "Queue is Empty" << endl;
            else
            {
                front = (front+1)%size;
                x = Q[front];
            }
            return x;
        }

        void display()
        {
            for(int i = front + 1; i <= rear; i++)
                cout << Q[i] << " ";
            cout << endl;
        }

        ~Queue()
        {
            delete []Q;
        }
};

int main()
{
    int arr[6] = {1,2,3,4,5,6};
    Queue q(arr,6);
    q.display();

    return 0;
}