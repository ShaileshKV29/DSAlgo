#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int Top;
    int *s;
};

int main()
{
    struct Stack st;
    printf("Enter Size of Stack: ");
    scanf("%d", &st.size);

    st.s = new int[st.size];
    st.Top = -1;

    return 0;
}