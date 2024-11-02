#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include<assert.h>

int main(void)
{
	glob_t pglob;
//	int result = glob("/Users/divyeshkanagavel/Desktop/DSA_cpp/programming/c_programs/*.c", 0, NULL,&pglob);
        // GLOB FLAG example
	int result = glob("/Users/divyeshkanagavel/Desktop/DSA_cpp/programming/c_programs/*/*",GLOB_MARK | GLOB_NOSORT,NULL,&pglob);
	printf("%zu\n",pglob.gl_pathc);
	for(size_t i = 0; i < pglob.gl_pathc;i++)
	{
		printf("%zu : %s\n",i,pglob.gl_pathv[i]);
	}
	globfree(&pglob);
	return 0;
}

