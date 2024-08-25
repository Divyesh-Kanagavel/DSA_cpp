#include <stdio.h>

int bitcount_fast(unsigned x)
{
    int b=0;
    while(x)
    {
        x &= (x-1);
        ++b;
    }
    return b;

}
int main(void)
{
    unsigned x = 7;
    printf("the number of 1 bits is %d\n", bitcount_fast(x));
    return 0;
}