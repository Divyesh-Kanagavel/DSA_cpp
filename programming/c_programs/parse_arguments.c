#include <stdio.h>
#include <unistd.h> // contains tools to parse arguments

// getopt basically 

int main(int argc, char** argv)
{
	int option;
	while((option=getopt(argc, argv, "a:b"))!=-1)
	{
	    switch(option)
	    {
	        case 'a':
		    printf("got a! : %s\n", optarg);
		    break;
		case 'b':
		    printf("got b!\n");
		    break;
            }
	}
        // optind is a global variable which tracks how many options are passed in getopt
	for(int i = optind;i<argc;i++)
	{
		printf("the argument %d is %s\n", i, argv[i]);
	}

	return 0;
}
