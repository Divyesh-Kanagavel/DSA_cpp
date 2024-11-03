#include <cstdio>

int main()
{
	char lower[] = "abc?e";
	char upper[] = "ABC?E";

	char *upper_ptr = upper;

	lower[3] = 'd';
	upper_ptr[3] = 'D';

	printf("%s\n",lower);
	printf("%s\n",upper_ptr);

	lower[7] = 'g' ; // this is the part where buffer overflow happens. only 6 element memory is allocated for lower. so ,when we access 7 we are accessing
			 // memory which is not allotted for lower by the system.this triggers undefined behaviour [crash, security vulnerability]
	
	return 0;
}
