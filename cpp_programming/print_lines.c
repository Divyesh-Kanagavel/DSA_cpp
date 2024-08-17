#include <stdio.h>
#define MAXLINE 10

int getline_naive(char line[], int maxline); // get the length of the maxline and the line itself with all characters
void copy(char to[], char from[]);

int main()
{
    int len; // length of current line

    char line[MAXLINE]; // current input line

    
    while ((len = getline_naive(line, MAXLINE)) > 0)
    {
        printf("length is : %d\n", len);
        if (len < (MAXLINE-1))
        {
            printf("%s",line);
        }
        else
        {
            line[len-1] = '\n'; // overwriting the last character with newline.
            printf("%s", line);
        }
    }   
}

int getline_naive(char line[], int maxline)
{
    int c,i;
    for(i=0; (i < (maxline-1)) && ((c = getchar())!=EOF) && (c!='\n'); ++i)
    {
        line[i] = c;
    }
    if (c == '\n')
    {
        line[i] = '\n';
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;
    i=0;
    while((to[i] = from[i])!='\0')
       ++i;
}