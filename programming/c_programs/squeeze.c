/* remove all occurences of a character from a string */
#include <stdio.h>

void squeeze(char s[],int c)
{
    int i, j;
    for(i=j=0;s[i]!='\0';i++)
    {
       if (s[i]!=c)
       {
            s[j++] = s[i];
       }
    }
    s[j] = '\0';
}

int main(void)
{
    char s[] = "hello world!";
    squeeze(s,'o');
    printf("%s\n",s);
    return 0;
}