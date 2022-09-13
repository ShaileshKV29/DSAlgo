#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> m;
    m[1] = 1;
    m[2] = 2;
    m[3] = 3;
    m[4] = 4;
    m[5] = 5;
    m[6] = 6;
    m[7] = 7;
    for(auto x: m)
    {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}