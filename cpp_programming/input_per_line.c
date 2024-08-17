/* Write a program that prints its input one word per line.*/

#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

int main()
{
    int c, prev;
    prev = EOF;
    while((c=getchar())!=EOF)
    {
        if ((c=='\n')||(c=='\t')||(c==' '))
        {
            if ((prev!='\n')&&(prev!='\t')&&(prev!=' '))
            {
                putchar('\n');
            }

        }
        else
        {
            putchar(c);
        }
        prev = c;
    }
    return 0;

  return 0;
}