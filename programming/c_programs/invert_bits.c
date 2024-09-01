/* Writeafunctioninvert(x,p,n)thatreturnsxwiththenbits that begin at position p inverted (i.e., 1changed into 0 and vice versa), leaving the others unchanged.*/

#include <stdio.h>

unsigned get_bits(unsigned x, int p , int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}
unsigned set_bits(unsigned x, int p, int n, unsigned y)
{
    unsigned temp1 = (y & (~(~0 << n))) << (p+1-n);
    unsigned temp2 = (~0 & (~(~0 << n))) << (p+1-n);
    return ((x & ~temp2) | temp1);
}
unsigned invert_bits(unsigned x, int p, int n)
{
    unsigned temp = get_bits(x,p,n);
    return set_bits(x,p,n,~temp);

}
int main(void)
{
    unsigned int x = 1092;
    int p = 4;
    int n = 3;
    printf("%u\n", invert_bits(x,p,n));
    return 0;
}