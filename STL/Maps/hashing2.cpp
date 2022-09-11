#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<int, int> m;
    int arr[] = {2,2,2,3,434,5,56,678,9,1,1,12,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < n; i++)
    {
        if(m[arr[i]])
            m[arr[i]]++;
        else
            m[arr[i]] = 1;
    }

    for(auto x: m)
    {
        cout << x.first << "            " << x.second << endl;
    }

    return 0;
}