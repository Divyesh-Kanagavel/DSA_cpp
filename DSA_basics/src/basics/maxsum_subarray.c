#include <stdio.h>

int maxsumSubArr(int xs[], int len)
{
	int maxGlobalSum = 0;
	int maxSum=0;
	for(int i=0;i<len;i++)
	{
		maxSum += xs[i];
		if (maxSum < 0)
		{
			maxSum = 0;
		}
		if (maxGlobalSum < maxSum)
		{
			maxGlobalSum = maxSum;
		}
	}
	return maxGlobalSum;
}

int main()
{
	int xs[] = {2,4,-1,7,3,5,-3,9,1,-7,4};
	int len = sizeof(xs)/sizeof(xs[0]);
	printf("%d\n", maxsumSubArr(xs,len));
	return 0;
}
