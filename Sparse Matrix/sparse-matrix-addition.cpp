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
        Sparse operator+(Sparse &s1);

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

Sparse Sparse::operator+(Sparse &s)
{
    Sparse *sum;
    if(m != s.m && n != s.n)
    {
        return *sum;
    }
    sum->m = s.m;
    sum->n = s.n;
    sum->e = new Element[num + s.num];

    int i = 0, j = 0, k = 0;
    while( i < num && j < s.num)
    {
        if(e[i].i < s.e[j].i)
            sum->e[k++] = e[i++];
        else if(e[i].i > s.e[j].i)
            sum->e[k++] = s.e[j++];
        else
        {
            if(e[i].j < s.e[j].j)
                sum->e[k++] = e[i++];
            else if(e[i].j > s.e[j].j)
                sum->e[k++] = s.e[j++];
            else
            {
                sum->e[i].i = e[i].i;
                sum->e[i].j = e[i].j;
                sum->e[k++].x = e[i++].x + s.e[j++].x;
            }
        }
    }
    for(;i<num;i++) sum->e[k++] = e[i];
    for(;j<s.num;j++) sum->e[k++] = s.e[j];
    sum->num = k;

    return *sum;
}

int main()
{
    // int A[6][3] = {{5,6,5}, {1,4,6}, {2,2,7}, {3,2,2}, {3,4,5}, {5,1,4}};
    // int B[7][3] = {{5,6,6}, {2,2,3}, {2,5,5}, {3,3,2}, {3,6,7}, {4,4,9}, {5,1,8}};

    Sparse s1, s2, s;
    cin >> &s1 >> &s2;
    cout << s1;
    cout << endl;
    cout << s2;

    s = s1 + s2;
    cout << endl;
    cout << s;

    return 0;
}