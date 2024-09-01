#include <stdio.h>
#include <ctype.h>

int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + 'a' - 'A';
    }
    else if (c >= 'a' && c <= 'z')
    {
        return c;
    }
    else
    {
        return -1;
    }
}

int main(void)
{
    char ch = 'B';
    printf("%c\n", lower(ch));
    // Library functions which take addiitonal edge cases into consideration + work for character sets apart from standard ASCII

    printf("%c\n", tolower(ch));
    printf("%d\n", isdigit('a'));
    return 0;
}