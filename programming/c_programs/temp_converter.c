#include <stdio.h> // library files includes

/* print Fahrenheit-Celsius table 
   for fahr = 0,10,20,30,40... */

int main()
{
    int fahr, celsius;
    int lower, upper, step;
    lower = 0;    // lower temperature in Fahrenheit
    upper = 300;  // higher limit of temperature in Fahrenheit
    step = 20;    // step size
    fahr = lower;
    while (fahr <= upper)
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr += step;
    }
    return 0;

}