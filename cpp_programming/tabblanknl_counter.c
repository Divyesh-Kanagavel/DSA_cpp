/* a program to count tabs,blanks and newlines in inputs */

#include <stdio.h>

int main()
{
    int c, tc, bc, nl; // tab counter, blank counter, newline counter
    tc = bc = nl = 0;
    while((c=getchar())!=EOF)
    {
        if (c == '\n')
        {
            ++nl;
        }
        if (c == '\t')
        {
            ++tc;
        }
        if (c == ' ')
        {
            ++bc;
        }

    }
    printf("%d\t%d\t%d\n", tc, bc, nl);
}