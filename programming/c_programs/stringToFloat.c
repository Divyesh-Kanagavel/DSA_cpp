// convert string to float -> atof function in standard library provides a more efficient n

#include <stdio.h>
#include <ctype.h>
double atof_(char s[])
{
    double val, power;
    int i,sign;
    for(i=0;s[i] == ' ';i++) // skip whitespaces 
    ;
    sign = (s[i] == '-')?-1:1;
    if (s[i] == '+' || s[i] == '-')
	  i++;
    for(val = 0.0;isdigit(s[i]);i++)
    {
        val = 10.0 * val + (s[i]-'0');
    }
    if (s[i] == '.')
	    i++;
    for(power=1.0;isdigit(s[i]);i++)
    {
	val = 10.0*val + (s[i]-'0');
	power = power * 10.0;
    }
    printf("%lf\n",val);
    return sign * val/power;
}


