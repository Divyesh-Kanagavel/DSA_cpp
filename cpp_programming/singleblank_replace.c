/* a program to replace multiple blanks with single blank*/

#include <stdio.h>
int main()
{
    int c,prev;
    while((c=getchar())!=EOF)
    {
        if (c == ' ' && prev == ' ')
        {
            prev = c;
        }
        else
        {
            putchar(c);
            prev = c;
        }
    }
    return 0;
}