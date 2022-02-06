#include<stdio.h>

int validate(char *name)
{
    for(int i = 0; name[i] != '\0'; i++)
    {
        if(!(name[i] >= 65 && name[i] <= 90) && !(name[i] >= 97 && name[i] <= 122) && !(name[i] >= 48 && name[i] <= 57))
            return 0;
    }
    return 1;
}

int main()
{
    char *name = "Aniplex29";
    if(validate(name))
        printf("Valid String");
    else
        printf("Invalid String");

    return 0;
}