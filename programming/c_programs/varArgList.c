#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>

int sum_all(int count, ...) // ... denotes variable argument and the count denotes num of arguments which will be supplied
{
	va_list ap;
	va_start(ap,count);
	int sum=0;
	for(int i=0;i<count;i++)
	{
		int x = va_arg(ap,int);
		sum += x;
	}
	va_end(ap);
	return sum;
}


int main(void)
{
	printf("%d\n",sum_all(3,5,1,2));
	return 0;
}
