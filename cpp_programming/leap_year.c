#include <stdio.h>

/* operator precedence 
+,-  have same precedence < *,/,% < unary +,-*/
/* Arithmetic operators associate left to right .*/

/* relational operators 
 >,<, >=, <= same precedence > ==, !=*/
/*Relation operators < arithmetic operators in precedence.*/

/* logical operators && , || associated left to right and evaluation stops upon encountering truth or falsehood.*/

/* && > || , logical < relational, != > assignment = */

int is_leap(int year);
int main(void)
{
    int year = 2020;
    printf("is the year %d a leap year? 1 for yes and 0 for no : %d\n", year, is_leap(year));
    return 0;
}

int is_leap(int year)
{
    return (((year % 400) == 0) || (((year%4)==0) && ((year%100)!=0)));
}