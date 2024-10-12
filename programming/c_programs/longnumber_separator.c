#include <stdio.h>
#include <stdint.h>

int main()
{
	int x = 1'000'000; // long number separator - add compiler flag std=c2x
	printf("%ld\n",x);
	return 0;
}


