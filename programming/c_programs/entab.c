#include <stdio.h>

#define TAB_LENGTH 8

int main(void)
{
    int c,prev,no_spaces,no_tabs;
    no_spaces = 0;
    while((c=getchar())!=EOF)
    {
        // ENTAB
        if (c == ' ')
        {
            ++no_spaces;
            prev = c;
        }
        else if (c!=' ' && prev == ' ')
        {
            no_tabs = no_spaces / TAB_LENGTH;
            no_spaces = no_spaces % TAB_LENGTH;
            while(no_tabs)
            {
                putchar('\t');
                --no_tabs;
            }
            while(no_spaces)
            {
                putchar(' ');
                --no_spaces;
            }
            prev = c;
            putchar(c);
            no_spaces = 0;
        }
        else
        {
            putchar(c);
            prev = c;
        }
    }
}