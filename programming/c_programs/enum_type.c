#include <stdio.h>

enum FOO : int  // with c23 standard, we have a option of specifying the type of enum 
{
	FOO_A,
	FOO_B
};

int main()
{
	enum FOO x = FOO_A;
	printf("sizeof(x) = %d\n",sizeof(x));
	return 0;
}
