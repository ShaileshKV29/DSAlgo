#include <iostream>
using namespace std;

void fun(int n)
{
    if(n > 0)
    {
        fun(n - 1);
        cout << n << endl;
    }
}

int main(int argc, char const *argv[])
{
    fun(6);
    return 0;
}
