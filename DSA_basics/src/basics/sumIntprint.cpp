// program to find the sum of integer digits

#include <cstdio>

int printDigitSum(int num)
{
    int sum = 0;
    if (num /10 == 0)
        return num % 10;
    sum += num % 10 + printDigitSum(num/10);
    return sum;
}
int main(void)
{
    int num = 1984;
    int sum_digits = printDigitSum(num);
    printf("%d\n", sum_digits);
    return 0;
}