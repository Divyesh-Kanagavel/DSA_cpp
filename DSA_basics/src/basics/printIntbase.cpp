#include <cstdio>

// print an integer digit by digit given a base using recursion

void printInt(int x, int base)
{
    char* conversion = "0123456789ABCDEF";
    char digit = x % base;
    if (x/=base)
    {
        printInt(x, base);
    }
    printf("%c",conversion[digit]);
}

int main(void)
{
    int x = 2345;
    printInt(x, 16);
    printf("\n");
    return 0;
}