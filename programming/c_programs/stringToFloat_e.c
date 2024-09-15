// extended version of atof -> taking in scientific notation
// convert string to float -> atof function in standard library provides a more efficient n

#include <stdio.h>
#include <ctype.h>
double atof_(char s[])
{
    double val, power,exp_val,exp_mul;
    int i,sign, exponent_sign;
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
    if (s[i] == 'e' || s[i] == 'E')
    {
	    i++;
    }
    exponent_sign = (s[i] == '-')?-1:1;
    if (s[i] == '+' || s[i] == '-')
	    i++;
    for(exp_val = 0.0;isdigit(s[i]);i++)
    {
	   exp_val = 10.0 * exp_val + (s[i]-'0'); 
    }
    exp_mul = 1.0;
    for (i=1;i<=exp_val;i++)
    {
	    if (exponent_sign == 1)
	       exp_mul *= 10.0;
	    else
               exp_mul /= 10.0;
    }

    return sign * (val / power) * exp_mul;
}


int main()
{
	char str[] = "23434.3423e-2";
	printf("the number : %lf\n", atof_(str));
	return 0;
}


















