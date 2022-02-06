class Name
{
    public:
        int name;
};

#include <iostream>
using namespace std;

namespace First
{
    void display()
    {
        cout << "Hello" << endl;
    }
}

namespace Second
{
    void display()
    {
        cout << "hello 2" << endl;
    }
}

int main()
{
    First::display();
    Second::display();

    return 0;
}