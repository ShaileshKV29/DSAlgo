#include<iostream>
using namespace std;

template <class T>
class Calculator
{
    private:
        T a;
        T b;

    public:
        Calculator(){
            this->a = 0;
            this->b = 0;
        }
        Calculator(T x, T y);
        T add();
        T sub();
        T multiply();
        T divide();
};

template <class T>
Calculator<T>::Calculator(T x, T y)
{
    this->a = x;
    this->b = y;
}

template <class T>
T Calculator<T>::add()
{
    return a + b;
}

template <class T>
T Calculator<T>::sub()
{
    return a - b;
}

template <class T>
T Calculator<T>::multiply()
{
    return a*b;
}

template <class T>
T Calculator<T>::divide()
{
    return a/b;
}

int main()
{
    float num1, num2;
    cout << "Welcome TO All Purpose Calculator" << endl;
    cout << "Enter the Values : " << endl;
    cin >> num1;
    cin >> num2;

    // string dataType = "int";
    // cout << "Enter the data type of value(int/float) : ";
    // cin >> dataType;

    Calculator<float> cal(num1, num2);

    cout << endl;

    string choice;
    cout << "Here are your operation Choice(+,-,*,/) : ";
    cin >> choice;

    cout << endl;

    if(choice == "+"){cout << cal.add();}
    else if (choice == "-"){cout << cal.sub();}
    else if (choice == "*"){cout << cal.multiply();}
    else if (choice == "/"){cout << cal.divide();}
    



}