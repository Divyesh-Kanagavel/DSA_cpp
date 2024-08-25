#include <stdio.h>

int main(void)
{
    int a = 10; // 10 is a integer constant
    unsigned int b = 10u; // 10 unsigned integer constant.
    unsigned long int c = 1000ul; // ul or UL meaning unsigned long integer.
    double d = 1.234; // 1.234 by default has double precision
    float e = 1.234f; // f or F suffix for float
    long double f = 1.234L; //L or l suffix for long double
    int g = 037; // 0 prefix meaning octal -> equivalent to base 10 31.
    int h = 0xFF; // 0x prefix meaning hexadecimal -> equivalent to base 16 255

    printf("%d , %d\n", g,h);
    
}