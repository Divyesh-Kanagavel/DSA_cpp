#include<stdio.h>
#include <fnmatch.h>
#include <assert.h>
#include <stdlib.h>

int main()
{
	char * s  = "path//to//file";
	int result = fnmatch("path//*file",s,FNM_NOMATCH);
	if(result == 0)
	{
		printf("match!\n");
	}
	else if (result == FNM_NOMATCH)
	{
		printf("no match!\n");
	}
	return 0;
}
