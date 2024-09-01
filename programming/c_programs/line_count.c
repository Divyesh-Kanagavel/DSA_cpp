/* a program to count number of lines in input */
#include <stdio.h>

int main()
{
    int c, nl;
    nl = 0;
    while((c=getchar())!=EOF)
    {
        if (c == '\n') // '\n internally uses a mapping to map to ASCII integral code which can be used as well
                       // but this makes the program easier to understand and makes the program independent of character set.
         {
            ++nl;
        }
    }
    printf("%d\n",nl);
    return 0;
}