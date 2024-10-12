#include <stdio.h>

int main()
{
	int a = 1;
	printf("%d\n",-32);
	printf("%u\n",23);
	printf("%f\n",45.34);
	printf("%p\n", &a);
	printf("%c\n",'a');
	printf("%s\n", "hello");
	printf("%%\n");
	printf("%g\n",123.123);
	printf("###%5f###\n", 23.21);
	printf("### %d###\n",32); // useful to align negative and positive integers.
	printf("%*.*f\n",5,2,139.10010);
	return 0;
	
}
