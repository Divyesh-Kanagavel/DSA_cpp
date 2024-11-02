#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <regex.h>
#include <string.h>

int main()
{
	regex_t preg;
	/*
	assert(regcomp(&preg,"ab+",REG_EXTENDED)==0); 
	int result = regexec(&preg, "a",0,NULL,0);
        if(result == 0)
	{
	    printf("match!\n");
	}
        if (result == REG_NOMATCH)
	{
	    printf("no match!\n");
	}
        */
	// group regex
	assert(regcomp(&preg, "(ab*)(cd*)",REG_EXTENDED)==0);
	const size_t nmatch=10;
        regmatch_t pmatch[nmatch+1];
	char *s = "abbcddddd";
	int result = regexec(&preg, s,nmatch,  pmatch,0);
        if (result == 0)
	{
	    printf("match!\n");
            for(size_t i=0; pmatch[i].rm_so!=-1 && i < nmatch; i++)
	    {
		    char buf[256] = {0};
		    strncpy(buf, s + pmatch[i].rm_so, pmatch[i].rm_eo - pmatch[i].rm_so);
		    printf("start %d, end %d : %s\n",pmatch[i].rm_so, pmatch[i].rm_eo,buf);
	    
	  }
	}
        else if (result == REG_NOMATCH)

	{
		printf("no match!\n");
	}
        regfree(&preg);

	return 0;
}
