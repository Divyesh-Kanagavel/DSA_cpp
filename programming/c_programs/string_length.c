#include <stdio.h>

int strlen(char s[])
{
    int i = 0;
    while(s[i]!='\0')
    {
        ++i;
    }
    return i;
}

int main()
{
    char s[] = "hello, world!";
    printf("%d\n", strlen(s));
}