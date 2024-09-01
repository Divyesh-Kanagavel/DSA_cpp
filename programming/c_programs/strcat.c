#include <stdio.h>

void strcat(char s[], char t[])
{
    int i,j;
    i=j=0;
    while(s[i]!='\0')
    {
        i++;
    }
    while((s[i++] = t[j++])!='\0')
    ;
}
int main(void)
{
    char s[40] = "hello ";
    char t[10] = "world\n";
    strcat(s,t);
    printf("%s", s);
}