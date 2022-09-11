#include<iostream>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
    // Creation
    unordered_map<string ,int> m;

    string str[] = {"One", "Two", "One", "Two", "Three", "Three", "Four", "One"};
    int n = 8;
    for(int i = 0; i < n; i++)
    {
        if(m[str[i]])
            m[str[i]]++;
        else
            m[str[i]] = 1;  
    }

    cout << m["One"];

    return 0;
}