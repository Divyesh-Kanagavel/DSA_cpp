/* Write the function any (s1, s2), which returns the first location ni the string s1 where any character from the string s2 occurs, or - 1 if s1 contains no characters from s2.*/

#include <stdio.h>

int any(char s[], char p[])
{
    int i=0,j=0;
    while(s[i]!='\0')
    {
        j=0;
        while(p[j]!='\0')
        {
            if (s[i] == p[j])
            {
                return i;
            }
            ++j;
        }
        ++i;
    }
}

int main(void)
{
    char s[] = "hello";
    char p[] = "world!";
    printf("%d\n",any(s,p));
    return 0;
}