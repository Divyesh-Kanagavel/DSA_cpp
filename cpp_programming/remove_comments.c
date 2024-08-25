#include <stdio.h>

#define MAXSTRLEN 1000

int get_str(char str[], int max_strlen);
void remove_comments(char str[], char comremoved_str[]);

int main(void)
{
    char str[MAXSTRLEN]; // input string
    char comremoved_str[MAXSTRLEN];  // string with comments removed

    get_str(str, MAXSTRLEN);

    remove_comments(str, comremoved_str);

    printf("%s\n", comremoved_str);
    return 0;
}

int get_str(char str[], int max_strlen)
{
    int c,i;
    i=0;
    while((i<max_strlen-1) && ((c=getchar())!=EOF))
    {
        str[i++] = c;
    }
    str[i] = '\0';
    return i;
}

void remove_comments(char str[], char comremoved_str[])
{
    int i,j;
    i=0;
    j=0;
    int IN_QUOTE = 0;
    int IN_BLOCK = 0;
    int IN_LINE = 0;
    while(str[i]!='\0')
    {
        if (!IN_BLOCK)
        {
            if (!IN_QUOTE && (str[i] == '"'))
            {
                IN_QUOTE = 1;
            }
            else if (IN_QUOTE && (str[i] == '"'))
            {
                IN_QUOTE = 0;
            }
        }

        if (!IN_QUOTE)
        {
            if (str[i] == '/' && str[i+1] == '*' && !IN_LINE)
            {
                IN_BLOCK = 1;
            }

            if (str[i] == '*' && str[i+1] == '/' && IN_BLOCK)
            {
                IN_BLOCK = 0;
                i+=2;
            }
            
            if (str[i] == '/' && str[i+1] == '/')
            {
                IN_LINE = 1;
            }

            if (str[i] == '\n')
            {
                IN_LINE = 0;
            }
            if (IN_LINE || IN_BLOCK)
            {
                ++i;
            }

            else if (!IN_LINE && !IN_BLOCK)
            {
                comremoved_str[j++] = str[i++];
            }
        }
        else
        {
            comremoved_str[j++] = str[i++];
        }
    }
    comremoved_str[j] = '\0';
}