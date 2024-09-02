#include <stdio.h>
#define MAXLEN 100

void rev_escape(char s[],char t[]);

int main(void)
{
    char s[MAXLEN] = "hello world!\\tI\\tam Divyesh\\n";
    printf("%s",s);
    char t[MAXLEN];
    rev_escape(s,t);
    printf("\n");
    printf("%s",t);
    printf("\n");
    return 0;

}

void rev_escape(char s[], char t[])
{
    int i,j;
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if (s[i] == '\\')
        {
            switch(s[i+1])
            {
                case 't':t[j] = '\t';
                break;
                case 'n':t[j] = '\n';
                break;
                default : break;
            }
            j++;
            i++;
        }
        else
        {
            t[j++] = s[i];
        }

    }
}

