/* Write the function i t o b ( n , s , b ) that converts the integer n into a base b character representationi n the string s.*/

// base 2, 8, 16 considered

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXLEN 1000

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
void itob(int n, char s[], int b)
{
    
    if (!((b==2)||(b==8)||(b==16)))
    {
        printf("try base 2,8 or 16 only!");
        return;
    }
    int i,sign,remainder;
    if ((sign=n) < 0) //  if negative make it positive
    {
        n=-n;
    }
    i=0;
    do
    {
        remainder = abs(n)%b;
        if (remainder > 9)
        {
            s[i++] = remainder - 10 + 'A';
        }
        else
        {
            s[i++] = remainder + '0';
        }

    } while ((n/=b) > 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);   
}

int main(void)
{
    int n = -2491;
    char s[MAXLEN];
    itob(n, s, 11);
    printf("%s\n", s);
    return 0;

}