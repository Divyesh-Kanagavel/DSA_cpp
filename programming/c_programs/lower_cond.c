/*Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of if-else.*/
#include <stdio.h>

int lower_cond(int c)
{
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}

int main()
{
    char ch = 'B';
    printf("%c\n", lower_cond(ch));
    return 0;
}