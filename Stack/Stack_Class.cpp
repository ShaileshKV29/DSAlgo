#include<iostream>
using namespace std;

class Stack
{
    public:
        int size;
        int Top;
        int *s;

        Stack(int size)
        {
            this->size = size;
            this->s = new int[this->size];
            int Top = -1;
        }
};

int main()
{
    int size;
    printf("Enter the Size of Stack: ");
    scanf("%d", &size);
    Stack st(size);

    return 0;
}