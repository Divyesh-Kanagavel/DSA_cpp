#include <stdio.h>
#include <string.h>

//the strtok function can be used to split the string based on a delimiter , in this case ",".
// it basically parses through the string and puts , in place of , a NULL character thereby splitting string without allocation.
// does not work if the string contains the empty string,it skips such instances.
// strsep on the other hand has cleaner syntax and works well with even empty strings!
int main()
{
	char s[]  = "1,2,3,4,5";
	char s2[] = "1,2,3,4,,5";
	char *s_ptr = s2;
	char* token2;
	char *token = strtok(s,",");
	while(token!=NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL,",");
	}
	while((token2=strsep(&s_ptr, ","))!=NULL)
	{
		printf("%s\n", token2);
	}


	return 0;

}
