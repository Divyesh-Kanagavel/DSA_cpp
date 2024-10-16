#include <stdio.h>

int SequentialSearch(int xs[],int count,int val)
{
	for(int i=0;i<count;i++)
	{
		if (xs[i] == val)
		{
			return i;
		}
	}
	return -1; // if not found
}
int main()
{
	int xs[] = {1,89,3,2,4,90};
	int val = 3;
	int count = sizeof(xs)/sizeof(xs[0]);
	printf("%d\n",SequentialSearch(xs,count,val));
	return 0;
}
