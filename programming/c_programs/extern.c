#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE]; // current line
char longest[MAXLINE]; // longest line

int getline_naive(void); // function declaration
void copy(void);

int main()
{
    int len;
    extern int max; // max is a global variable, we are declaring it for use in function
    extern char longest[]; // this can be omitted if the definition is in the same source file and occurs before the function
    // in practice, it is common to put all definitions of all global variables at the top of source file and omit extern declarations in each function which uses it.

    // if program is spread out between multiple files, the declaration has to be done every time it is used.
    // usually the extern declarations are collected in a header file and it is included.
    max = 0;
    while((len = getline_naive()) > 0)
    {
        if (len > max)
        {
            max = len;
            copy();
        }
    }
    if (max > 0)
    {
        printf("printing the longest line\n");
        printf("%s\n", longest);
    }
    return 0;
}

int getline_naive(void)
{
    int c, i;
    extern char line[];
    for(i=0;(i<MAXLINE-1) && ((c=getchar())!=EOF) && (c!='\n');++i)
    {
        line[i] = c;
    }
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy(void)
{
    int i;
    extern char line[],longest[]; 
    i=0;
    while((longest[i]=line[i])!='\0')
    {
        ++i;
    }
}