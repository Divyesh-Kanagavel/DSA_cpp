#include <stdio.h>
#include <stdlib.h>



int add_int(int a, int b)
{
	return a+b;
}

float add_float(float a, float b)
{
	return a+b;
}

double add_double(double a, double b)
{
	return a+b;
}

//instead of having having three different apis for addition, we can combine them into single api using generics in c11

#define add(a,b) _Generic((a),    \
	int : add_int((a),(b)),    \
	float : add_float((a),(b)), \
	double : add_double((a),(b)), \
	default : printf("not sure of the data type") \
	)

int main()
{
	printf("add_int(4,5) = %d\n", add_int(4,5));
	printf("add_float(3.4,2.11) = %f\n", add_float(3.4,2.11));
	printf("add_double(4.3,2.1) = %lf\n",add_double(4.3,2.1));
	printf("\n");
        printf("add(4,5) = %d\n", add(4,5));
	printf("add(3.4,2.11) = %f\n", add(3.4,2.11));
	printf("add(4.3,2.1) = %lf\n",add(4.3,2.1));
	short a=3;short b= 3;
	printf("add(a,b) = %d\n",add(a,b));
	return 0;

}
