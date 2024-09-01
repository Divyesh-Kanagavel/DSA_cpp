/* Exercise : 
Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0*/

#include <stdio.h>

int main()
{
    int fahr;
    printf("Fahrenheit\tCelsius\n");
    for (fahr = 300; fahr >= 0; fahr=fahr-20) // for-loop , similar to while loop but initialization, termination condition and increment expressions are all grouped in this place.
    {
        printf("%10d\t%7.2f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
}