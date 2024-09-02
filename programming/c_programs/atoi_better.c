#include <stdio.h>
#include <ctype.h>

/* atoi : convert string to integer */
int atoi(char s[])
{
    int i, n, sign;
    /* skip whitespaces */
    for(i=0;isspace(s[i]);i++)
    {
        ;
    }
    sign = (s[i] == '-') ? -1 : 1;
    if ((s[i] == '+') || (s[i] == '-'))
    {
        i++;
    }
    for(n=0;isdigit(s[i]);i++)
    {
        n = 10 * n + (s[i] - '0');
    }
    return sign*n;

}

int main()
{
    char s[] = "   -3458";
    printf("%d\n", atoi(s));
    return 0;
}

// the standard library provides an elaborate function strtol to convert from string to long integers.