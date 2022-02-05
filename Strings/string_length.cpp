#include<iostream>
using namespace std;

int main()
{
    char *s = "Welcome";
    int i = 0;

    while(s[i] != '\0')
        i++;

    cout << i << endl;
    return 0;
}