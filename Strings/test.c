#include <stdio.h>

int main()
{
    char a, b, c;

    printf("Enter a : ");
    scanf("%c", &a);
    printf("Enter b: ");
    scanf(" %c", &b);

    if ((int)a == (int)b)
    {
        printf("Both character are same");
    }
    else
    {
        c = b - 32;
        printf("the oppostie case of the 2nd alphabet is %c", c);
    }

    return 0;
}