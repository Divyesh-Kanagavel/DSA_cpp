/* handling chars like integers with all their arithmetic operations permits
great flexibilty and helps us write some useful programs*/

#include<stdio.h>

int atoi(char s[]);

int main()
{
    char s[] = "345000";
    printf("%d\n", atoi(s));
    return 0;
}

int atoi(char s[])
{
    int n = 0;
    int i;
    for (i=0;s[i]>='0' && s[i]<='9';++i)
    {
        n = 10 * n + (s[i] - '0');
    }
    return n;
}