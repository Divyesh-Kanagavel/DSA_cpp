#include <stdio.h>

// rotate an array by k positions
// example : arr = {10,20,30,40,50,60} k=2 -> {30,40,50,60}
// soln : reverse sub arr till k -> {20,10} , reverse sub array k to n -> {60,50,40,30} then reverse full array -> {30,40,50,60,10,20}
// to reverse an array, there is a clever trick using XOR operations: to swap x,y : x = x^y, y = x ^ y, x = x^y. makes use of interesting properties:
// x ^ x = 0, x ^ 0 = x, x ^ (y ^ z) = (x ^ y) ^ z

void reverse_arr(int xs[],int n)
{
	for(int i=0, j=n-1;i<j;i++,j--)
	{
		xs[i] = xs[i] ^ xs[j];
		xs[j] = xs[j] ^ xs[i];
		xs[i] = xs[i] ^ xs[j];
	}
}

void rotate_arr(int xs[], int count, int k)
{
	reverse_arr(xs, k);
	reverse_arr(&xs[k],count-k);
	reverse_arr(xs,count);
}

int main()
{
	int xs[] = {10,20,30,40,50,60};
	int n = sizeof(xs)/sizeof(xs[0]);
	int k = 3;
	rotate_arr(xs, n, k);
	for(int i=0;i<n;i++)
	{
		printf("%d ", xs[i]);
	}
	printf("\n");
	return 0;
}
