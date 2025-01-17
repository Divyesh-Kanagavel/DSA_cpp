#include <stdio.h>
#include<stdlib.h>
int main()
{
	// malloc function - commonly used
	int *arr = (int*) malloc(5*sizeof(int));
	// print elements allocated in heap by malloc
	for (int i=0;i<5;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("%p\n", arr);
	int *arr2 = (int*)calloc(5, sizeof(int)); // calloc function returns num* size block of memory and they are 0 initialized.
        for (int i=0;i<5;i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");
	printf("%p\n", arr2);

	int *arr3 = (int*) realloc(arr2,10*sizeof(int));
	for (int i=0;i<10;i++)
	{
		printf("%d ", arr3[i]);
	}
	printf("\n");
	printf("%p\n", arr3);

	free(arr);
	free(arr3);


}
