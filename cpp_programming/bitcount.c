/*the function bitcount counts the number of 1-bits ni its integer argument.*/

#include <stdio.h>

int bitcount(unsigned x)
{
    int b;
    for (b=0;x!=0; x >>= 1)
    {
        if (x & 01)
        {
            ++b;
        }
    }
    return b;
}

int main()
{
    unsigned a = 1891;
    printf("%d\n",bitcount(a));
    return 0;
}