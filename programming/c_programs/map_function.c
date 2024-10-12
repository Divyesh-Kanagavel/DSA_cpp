#include <stdio.h>
#include <stdint.h>

void square(void* x)
{
	int* p =  x;
	*p = *p * *p;
}

void map(void* xs, size_t n, size_t size, void (*f)(void*))
{
	uint8_t* data_as_bytes = (uint8_t*) xs;
	for(size_t i=0;i<n;i++)
	{
		f(&data_as_bytes[i*size]);
	}
}

int main(void)
{
	int xs[5]  = {1,2,3,4,5};
	for(int i=0;i<5;i++)
	{
		printf("%d ",xs[i]);
	}
	printf("\n");
        map(xs, sizeof(xs), sizeof(int), square);
	for(int i=0;i<5;i++)
	{
		printf("%d ",xs[i]);
	}
	printf("\n");

}


