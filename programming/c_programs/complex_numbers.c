#include <stdio.h>
#include <complex.h>
#include <tgmath.h> // for generic math functions [for real and complex numbers]
#include <math.h>

int main()
{
	double complex c  = 2+3*I; // I macro is reserved to iota to represnet complex numbers
	printf("real  = %lf, imaginary = %lf\n",creal(c), cimag(c));

	double complex sin_ = sin(c);
	double complex cos_ = cos(c);
	double complex abs_ = cabs(c);
	printf("real  = %lf, imaginary = %lf\n",creal(sin_), cimag(sin_));
		printf("real  = %lf, imaginary = %lf\n",creal(cos_), cimag(cos_));
		printf("real  = %lf, imaginary = %lf\n",creal(abs_), cimag(abs_));
	return 0;
}

