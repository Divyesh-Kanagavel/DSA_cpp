/* in the temp_converter.c, there is a bug. Since integer data type is 
used to store variables, the accurate floating point values are rounded off to 
integers. The bug is fixed in this program with a prettier version of print. */

#include <stdio.h>

int main()
{
    float fahr, celsius;
    int lower, upper, step;
    lower = 0;    // lower temperature in Fahrenheit
    upper = 300;  // upper limit to temperature in Fahrenheit
    step = 20;    // step size
    fahr = lower;
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.2f\n", celsius, fahr);
        fahr += step;
    }
    return 0;
}