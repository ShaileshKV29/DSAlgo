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
        m[str[i]]++;
    }

    for(pair<string, int> x: m)
    {
        cout << x.first << "    " << x.second << endl;
    }

    return 0;
}