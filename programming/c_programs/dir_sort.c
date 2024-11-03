#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>

int main()
{
	struct dirent **entries;
	int n = scandir("/Users/divyeshkanagavel/Desktop/DSA_cpp",&entries,NULL, alphasort);
	for(int i=0;i<n;i++)
	{
		printf("%d : %s\n", i, entries[i]->d_name);
	}
	return 0;
}


