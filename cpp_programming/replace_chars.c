/* a program to replce tabs by \t , backspace by \b, backslash by \\*/

#include <stdio.h>
int main()
{
    int c;
    while((c=getchar())!=EOF)
    {
        if (c == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        else if (c == '\b') // on my terminal this does not work -> my terminal works in line mode
                            // meaning chars are stored in buffer, and all chars stored in line are then processed and shown in screen
                            // if terminal is moved to raw mode, this code will work.
        {
            putchar('\\');
            putchar('b');
        }
        
        else if (c == '\\')
        {
            putchar('\\');
            putchar('\\');
        } 
        else{
            putchar(c);
        }
    }
    return 0;
}