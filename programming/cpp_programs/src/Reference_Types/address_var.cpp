#include <cstdio>

int main()
{
        // each time the code is run, the address of var changes. this is done intentionally and is called memory layout randomization
	// this approach prevents hackers from adding exploits to the binary code, because the hacker is unaware of the memory location from where memory for the p// rogram is loaded.it is impossible to repurpose existing code to call APIs from where to load malicious payload.
	int var = 3;
	printf("the value of var is %d\n", var);
	printf("the address of var is %p\n", &var);
	return 0;
}
