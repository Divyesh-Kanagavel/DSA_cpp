/* Exercises
1.Modify the temperature conversion program to print a heading above the table. 
2.Write a program to print the corresponding Celsius to Fahrenheit table.  */

#include <stdio.h>

int main()
{
    // exercise 1:
    float fahr, celsius;
    int lower, upper, step;
    lower = 0;    // lower temperature in Fahrenheit
    upper = 300;  // upper limit to temperature in Fahrenheit
    step = 20;    // step size
    fahr = lower;
    printf("Fahrenheit\tCelsius\n");
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%10.0f\t%7.2f\n", fahr, celsius);
        fahr += step;
    }
    printf("\n\n");
    // exercise 2:
    celsius = lower;
    printf("Celsius\tFahrenheit\n");
    while(celsius <= upper)
    {
        fahr = (celsius * 9.0 / 5.0) + 32.0;
        printf("%7.0f\t%10.2f\n", celsius, fahr);
        celsius += step;
    }
    return 0;

}