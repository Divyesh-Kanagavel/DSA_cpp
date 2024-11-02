#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc/malloc.h>
#include <errno.h>
int main()
{
	errno = 0;
	char* filename = "/Users/divyeshkanagavel/Desktop/DSA_cpp/programming/c_programs/map_function.c";
	printf("%s\n",filename);
	FILE *file = fopen(filename,"r");
	if (file == NULL)
	{
		printf("%d\n", errno);
		perror(NULL);
	}
        char* line = NULL;
	size_t line_buffer_len = 0;
	ssize_t read_size;
	while((read_size = getline(&line, &line_buffer_len, file))!=-1)
	{
		line[read_size-1]='\0';
		printf("%s, allocated size is %zu\n",line, malloc_size((void*)line));
         }
	free(line);
	assert(feof(file));
	fclose(file);
	return 0;
}
