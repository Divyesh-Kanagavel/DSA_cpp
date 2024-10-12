#include <cstdio>

int step_fn(int x)
{
	int result=0;
	if (x < 0)
	{
		result = -1;
	}
	else if (x>0)
	{
		result = 1;
	}
	return result;
}

int main()
{
	int value1 = step_fn(-42);
	int value2 = step_fn(0);
	int value3 = step_fn(100);
	printf("Num 1 : %d, Step: %d\n",-42,value1);
        printf("Num 2 : %d, Step: %d\n",0,value2);
        printf("Num 3 : %d, Step: %d\n",100,value3);
	return 0;
}

