#include <cstdio>

// read digits of a integer and print it one by one using recursion

void printInt(int x)
{
    char digit = x % 10 + '0';
    if (x /= 10)
    {
        printInt(x);
    }
    printf("%c", digit);


}

int main(void)
{
    int x = 2345;
    printInt(x);
    printf("\n");
    return 0;
}