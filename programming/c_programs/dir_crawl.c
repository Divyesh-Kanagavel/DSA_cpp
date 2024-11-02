#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>

int main()
{
	DIR *dir = opendir("/Users/divyeshkanagavel");
	long entry_index = -1;
	struct dirent *entry;
	while((entry=readdir(dir))!=NULL)
	{
		if (entry_index == -1)
		{
			entry_index = telldir(dir);
		}
		printf("%ld : %s\n", telldir(dir), entry->d_name);
	}

	seekdir(dir, entry_index);

	while((entry=readdir(dir))!=NULL)
	{
		printf("%s\n", entry->d_name);
	}
	closedir(dir);

	return 0;
}
