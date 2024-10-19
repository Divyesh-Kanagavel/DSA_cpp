#include <stdio.h>
#include <assert.h>

// one way of handling errors is to use assert statement : it shows debug print statements with line number

int main()
{
	FILE *f = fopen("../split_string.c", "r");
	assert(f != NULL); // assert statement which will fail if f == NULL
	char c;
	while((c = fgetc(f))!=EOF)
	{
		putchar(c);
	}
	return 0;
}

