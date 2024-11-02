#include <stdio.h>
#include <assert.h>

#define FOO 42

static_assert(FOO==42); // assert for compile time checks


int main()
{
	const  int len = 23; 
	static_assert(len == 23); // works only when len is a const
	return 0;
}
