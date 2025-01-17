#include <stdio.h>

// return sum of elements of array

int sum_array(int a[], int count)
{
	int sum = 0;
	for(int i=0;i<count;i++)
	{
		sum += a[i];
	}
	return sum;
}

int main()
{
	int xs[] = {45,21,90,87,1,14};
	printf("%d\n",sum_array(xs, sizeof(xs)/sizeof(xs[0])));
	return 0;
}

