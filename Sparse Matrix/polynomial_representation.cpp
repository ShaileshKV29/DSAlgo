#include<iostream>
using namespace std;

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *t;
};

int main()
{
    struct Poly p;
    cout << "Enter Number of Terms: ";
    cin >> p.n;

    cout << "Enter Terms" << endl;
    for(int i = 0; i < p.n; i++)
    {
        cout << "Term No. " << i+1 << ": ";
        cin >> p.t[i].coeff >> p.t[i].exp;
    }

    return 0;
}