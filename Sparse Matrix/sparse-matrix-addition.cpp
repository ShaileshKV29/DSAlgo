#include<iostream>
using namespace std;

class Element
{
    public:
        int i;
        int j;
        int x;
};

class Sparse
{
    public:
        int m;
        int n;
        int num;
        Element *e;

        friend ostream & operator <<(ostream &o, Sparse s);
        friend istream & operator >>(istream &c, Sparse * s);
        friend Sparse operator+(Sparse s1, Sparse s2);

        ~Sparse()
        {
            delete []e;
        }
};


ostream & operator << (ostream &o, Sparse s)
{
    int i, j, k = 0;
    for(i = 0; i < s.m; i++)
    {
        for(j = 0; j < s.n; j++)
        {
            if(i == s.e[k].i && j == s.e[k].j)
                o << s.e[k++].x << " ";
            else
                o << "0 ";
        }
        o << endl;
    }

    return o;
}

istream & operator >>(istream &c, Sparse * s)
{
    cout << "Enter Dimension: ";
    c >> s->m >> s->n;
    cout << "Enter Number of Non Zero Elements: ";
    c >> s->num;
    s->e = new Element[s->num];
    cout << "Enter all Elements" << endl;
    for(int i = 0; i < s->num; i++)
    {
        c >> s->e[i].i >> s->e[i].j >> s->e[i].x;
    }

    return c;
}

Sparse operator+(Sparse s1, Sparse s2)
{
    Sparse sum;
    if(s1.m != s2.m && s1.n != s2.n)
    {
        cout << "Inside IF" << endl;
        return sum;
    }
    sum.m = s1.m;
    sum.n = s1.n;
    sum.e = new Element[s1.num + s2.num];

    int i = 0, j = 0, k = 0;
    while( i < s1.num && j < s2.num)
    {
        if(s1.e[i].i < s2.e[j].i)
            sum.e[k++] = s1.e[i++];
        else if(s1.e[i].i > s2.e[j].i)
            sum.e[k++] = s2.e[j++];
        else
        {
            if(s1.e[i].j < s2.e[j].j)
                sum.e[k++] = s1.e[i++];
            else if(s1.e[i].j > s2.e[j].j)
                sum.e[k++] = s2.e[j++];
            else
            {
                sum.e[i].i = s1.e[i].i;
                sum.e[i].j = s1.e[i].j;
                sum.e[k++].x = s1.e[i++].x + s2.e[j++].x;
            }
        }
    }
    sum.num = k;

    return sum;
}

int main()
{
    // int A[6][3] = {{5,6,5}, {1,4,6}, {2,2,7}, {3,2,2}, {3,4,5}, {5,1,4}};
    // int B[7][3] = {{5,6,6}, {2,2,3}, {2,5,5}, {3,3,2}, {3,6,7}, {4,4,9}, {5,1,8}};

    Sparse s1, s2, s;
    cin >> &s1;
    // s2.create();
    // s1.display();
    cout << s1;
    // cout << endl;
    // s2.display();

    // s = s1 + s2;
    // cout << endl;
    // s.display();

    return 0;
}