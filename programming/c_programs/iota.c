#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLEN 1000
 /* convert an int to string , reverse of atoi */
void reverse(char s[])
{
    int c,i,j;
    for(i=0,j=strlen(s)-1; i<j;i++,j--)
    {

        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void iota(int n, char s[])
{
    int i,sign;

    if ((sign=n) < 0) //  if negative make it positive
    {
        n = -n;
    }

    
    i=0;
    do
    {

        s[i++] = abs(n)%10 + '0';
    }while((n/=10) > 0);
    if (sign < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main()
{
    int n = -(2<<30)+1;
    char s[MAXLEN];
    iota(n,s);
    printf("%s\n", s);
    return 0;
}