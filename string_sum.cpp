#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    string n1 = "99";
    string n2 = "999";

    int r = 0;
    int size;
    int size_diff;
    if(n1.size() > n2.size())
    {
        size = n2.size();
        size_diff = n1.size() - n2.size();
        while(size_diff--)
        {
            n2 = '0' + n2;
        }
    }
    else
    {
        size = n1.size();
        size_diff = n2.size() - n1.size();
        while(size_diff--)
        {
            n1 = '0' + n1;
        }
    }

    int n1_size = n1.size();
    int n2_size = n2.size();

    string new_string = "";
    for(int i = n1.size()-1; i >= 0; i--)
    {
        int digit_sum=n1[n1_size-1] + n2[n2_size-1] - 96 + r;
        r = 0;

        if(digit_sum > 9)
        {
            r = digit_sum/10;
            digit_sum = digit_sum - 10;
        }

        char num_digit = digit_sum + 48;
        new_string = num_digit + new_string;
        // cout << num_digit << " " << r << " ";
        n1_size--;
        n2_size--;
    }
    if(r > 0)
    {
        new_string = (char)(r+48) + new_string;
    }
    cout << new_string;
    return 0;
}