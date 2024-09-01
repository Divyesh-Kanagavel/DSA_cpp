/*Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank l i n e */

#include <stdio.h>
#define MAXLINE 1000


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
void remove_trailing_blanks(char line[], int len)
{
    int i;
    for (i = len-2; ((line[i] == ' ') || (line[i] == '\t')); --i)
    ;
    line[i+1] = '\n';
    line[i+2] = '\0';
    printf("after removing trailing blanks, the len is %d\n", i+2);
}

int main()
{
    int len;
    char line[MAXLINE];
    char line_blanktabs[MAXLINE];
    while ((len = getline_naive(line, MAXLINE)) > 0)
    {
        printf("before removing trailing_blanks, the length is : %d\n", len);
        remove_trailing_blanks(line, len);
       
        printf("%s", line);
    }
}