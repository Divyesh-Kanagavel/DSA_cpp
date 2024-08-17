/* the standard library provides some useful functions to read and write characters
from/to the keyboard/screen. */
#include <stdio.h>

int main()
{
   int c; // char can be stored in int
   // the reason for using int is subtle. the variable c should be large 
   // enough to hold EOF in addition to other chars.
   /*
   c = getchar();
   while(c!=EOF) // EOF is a special character which denotes End Of File.
   {
        putchar(c);
        c = getchar();
   }
   */
   // a more concise way of copying input stream of characters to screen.
   while((c = getchar())!=EOF)
   {
        putchar(c);
   }
    return 0;
}