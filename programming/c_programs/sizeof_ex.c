#include <stdio.h>
#include<stdint.h>

int main()
{
	int xs[5] = {1,3,4,5,1};
	printf("size of array is : %d\n", sizeof(xs));
	int* ptr_xs = xs;
	printf("size of pointer to array xs is : %d\n", sizeof(ptr_xs));
        return 0;
}

