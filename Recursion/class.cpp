class Main
{
    public:
     int x;
};

#include <iostream>
using namespace std;

int main()
{
    Main m;
    m.x = 10;
    cout << m.x;
    return 0;
}