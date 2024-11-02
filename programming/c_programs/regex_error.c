#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <assert.h>

int main()
{
	regex_t preg;
	int result = regcomp(&preg, "ab***",0);
	if (result!=0) // if not a correct regular expression
        {
		const size_t err_buff_size = 129;
		char err_buff[err_buff_size+1];
		regerror(result,&preg, err_buff, err_buff_size);
		printf("regex error for %s : %s\n","ab***", err_buff);
		
	}
	regfree(&preg);
	return 0;
}

