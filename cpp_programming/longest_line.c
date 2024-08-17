#include <stdio.h>
#define MAXLINE 1000

int getline_naive(char line[], int maxline); // get the length of the maxline and the line itself with all characters
void copy(char to[], char from[]);

int main()
{
    int len; // length of current line
    int max; // maximum length seen so far
    char line[MAXLINE]; // current input line
    char longest[MAXLINE]; // longest line saved here
    max = 0;
    
    while ((len = getline_naive(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) // there was a line
    {
        printf("The maximum length of line is : %d\n", max);
        printf("%s",longest);
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