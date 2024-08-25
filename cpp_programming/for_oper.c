#include <stdio.h>
#define MAXLINE 1000
int main()
{
    char line[MAXLINE];
    int i,c;
    //while ((i < MAXLINE-1) && ((c=getchar())!='\n') && c !=EOF)
    //without && and || operator
    while ((i < MAXLINE-1) * ((c=getchar())!='\n') * (c !=EOF)) // replace && with * and || with +
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    printf("%s\n", line);
    return 0;

}