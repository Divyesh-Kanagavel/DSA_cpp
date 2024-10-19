#include <stdio.h>
#include <errno.h>
int main(void)
{
	FILE *f = fopen("../error1.c","r");
	if (f==NULL)
	{
		printf("%d\n", errno);
		perror(NULL);
	}
	else
	{
		char c;
		while((c = fgetc(f))!=EOF)
		{
			putchar(c);
		}
	}

	return 0;

}
