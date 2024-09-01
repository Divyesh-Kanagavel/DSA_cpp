/*
Exercises:
1.Verify that the expression getchar () |= BOF is 0 or 1.
2.Write a program to print the value of EoF.
*/

#include <stdio.h>

int main()
{
    int c;
    printf("the value of EOF is %d\n", EOF);
    c = getchar() != EOF;
    printf("%d\n", c);
    return 0;
    
}