#include<iostream>
#include<cmath>
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
    int x, sum;

    struct Poly p;
    cout << "Enter Number of Terms: ";
    cin >> p.n;

    cout << "Enter Terms" << endl;
    for(int i = 0; i < p.n; i++)
    {
        cout << "Term No. " << i+1 << ": ";
        cin >> p.t[i].coeff >> p.t[i].exp;
    }

    x = 0;

    // cout << endl << "Enter value of x: ";
    // cin >> x;

    // cout << "Evaluation" << endl;
    // for(int j = 0; j < p.n; j++)
    // {
    //     cout << "Term Value: " << pow(x, p.t[j].exp)*p.t[j].coeff << endl;
    //     sum += pow(x, p.t[j].exp)*p.t[j].coeff;
    // }

    // cout << "Evaluated Value is : " << sum << endl;

    return 0;
}