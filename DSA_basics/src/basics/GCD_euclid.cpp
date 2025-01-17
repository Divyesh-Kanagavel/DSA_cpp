#include <cstdio>

int GCD_Euclid(int a, int b)
{
    if (a < b)
    {
        return GCD_Euclid(b,a);

    }
    if (a%b == 0)
    {
        return b;
    }
    return GCD_Euclid(b, a%b);

}

int main(void)
{
    int a = 45;
    int b = 18;
    printf("%d\n",GCD_Euclid(a,b));
    return 0;
}