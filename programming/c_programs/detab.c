#include <stdio.h>
#define TAB_LENGTH 8 // tab length in this system is 8
int main(void)
{
    // tab length taken as a parameter to be read from the user.
    int c,no_spaces;

    printf("Enter the text\n");
    while((c=getchar())!=EOF)
    {
        if (c == '\t')
        {
            no_spaces = TAB_LENGTH;
            while(no_spaces)
            {
                putchar(' ');
                --no_spaces;
            }
        }
        else
        {
            putchar(c);
        }
    }
    return 0;

}