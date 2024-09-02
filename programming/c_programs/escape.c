#include <stdio.h>
#define MAXLEN 100

void escape(char s[],char t[]);

int main(void)
{
    char s[MAXLEN] = "hello\tworld!\nI\tam\tDivyesh\n";
    printf("%s",s);
    char t[MAXLEN];
    escape(s,t);
    printf("%s",t);
    printf("\n");
    return 0;

}

void escape(char s[], char t[])
{
    int i,j;
    for(i=0,j=0;s[i]!='\0';i++)
    {
        switch(s[i])
        {
            case '\t': t[j++] = '\\';
                       t[j] = 't';
                       break;
            case '\n': t[j++] = '\\';
                       t[j] = 'n';
                       break;
            default : t[j] = s[i];
            break;
        }
        j++;
    }
}

