#include<bits/stdc++.h> 
using namespace std;

int main()
{
    int a;
    cout << "Enter Number: ";
    cin >> a;
    cout << "Number is: " << a << endl;
    cout << "Binary : " << bitset<8>(a).to_string() << endl;
    int count = 0;
    while(a > 0)
    {
        if((a & 1) == 1)
            count++;
        a = a >> 1;
    }
    cout << "Count of 1 is: " << count << endl;

    return 0;
}