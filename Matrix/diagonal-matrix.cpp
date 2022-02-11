#include<iostream>
using namespace std;

class Diagonal
{
    int n;
    int *A;

    public:
        Diagonal(int n)
        {
            this->n = n;
            A = new int[n];
        }

        void Set(int i, int j, int element);
        int Get(int i, int j);
        void Display();
        ~Diagonal();
};

void Diagonal::Set(int i, int j, int element)
{
    if(i == j)
        A[i-1] = element;
}

int Diagonal::Get(int i, int j)
{
    if(i == j)
        return A[i-1];
    else
        return 0;
}

void Diagonal::Display()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
                cout << A[i-1] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

Diagonal::~Diagonal()
{
    delete []A;
}

int main()
{
    Diagonal matrix(5);
    matrix.Set(1,1,1);
    matrix.Set(2,2,2);
    matrix.Set(3,3,3);
    matrix.Set(4,4,4);
    matrix.Set(5,5,5);
    matrix.Display();

    return 0;
}