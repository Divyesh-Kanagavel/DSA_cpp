#include <stdio.h>

unsigned get_bits(unsigned x, int p , int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

int main(void)
{
    int x = 500;
    printf("%d\n",get_bits(500,4,3));
    return 0;
}