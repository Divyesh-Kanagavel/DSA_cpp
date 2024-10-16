#include <cstdio>

// three levels of precision offered by c++:
// 1. Single precision (float), 2. Double precision (double) 3. Extended precision (long double)

int main()
{
    float a = 1.0F;
    double b = 0.2;
    long double c = 0.3L; // extended precision
    printf("%f\n", a);
    printf("%lf\n", b);
    printf("%Lf\n", c);

    // scientific notation
    double d = 6.022e23;
    printf("%lf\n", d);
    printf("%le\n", d); // exponential notation
    printf("%lg\n",d); // printf decides b/w compact or scientific notation
    return 0;
}