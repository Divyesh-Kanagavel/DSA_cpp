#include <cstdio>

int main()
{
    // binary
    unsigned short a = 0b10101010;
    printf("%hd\n", a);
    // octal
    int b = 01234;
    printf("%d\n", b);
    // hexadecimal
    unsigned long long c = 0xFFFFFFFFFFFFFFFF;
    printf("%llu\n",c);
    return 0;
}