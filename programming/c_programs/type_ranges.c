#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    //making use of library to determine ranges
    printf("the range of char is %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("the range of short is %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("the range of int is %d to %d\n", INT_MIN, INT_MAX);
    printf("the range of long is %lu to %lu\n", LONG_MIN, LONG_MAX);
    printf("the range of signed char is %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("the range of unsigned char is %d to %d\n", 0, UCHAR_MAX);
    printf("the range of unsigned int is %lu to %lu\n", 0, UINT_MAX);
    printf("the range of unsigned long is %lu to %lu\n", 0, ULONG_MAX);

    // floating point values
    printf("the max floating exponent is %d\n", FLT_MAX_10_EXP);
    printf("The max floating point digit %d\n", FLT_DIG);
    printf("the range of floating point values are %f to %f\n",FLT_MIN, FLT_MAX );

    printf("the max floating exponent double is %d\n", DBL_MAX_10_EXP);
    printf("The max floating point digit double %d\n", DBL_DIG);
    printf("the range of floating point values double are %lf to %lf\n",DBL_MIN, DBL_MAX );
}

