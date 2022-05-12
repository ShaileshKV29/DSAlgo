#include<iostream>
#include<array>
using namespace std;

int main()
{
    array<int, 10> arr = {1,2,3,4,5,6,7,8,9,10};
    int size = arr.size();
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << arr.at(9) << endl;
    cout << arr.empty() << endl;
    cout << "First Element: " << arr.front() << endl;
    cout << "Last Element: " << arr.back() << endl;
    return 0;
}