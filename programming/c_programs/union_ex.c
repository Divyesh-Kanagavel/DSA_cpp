#include <stdio.h>
#include <stdint.h>

enum tag
{
	TAG_BOOL,
	TAG_INT,
	TAG_FLOAT
};

struct dynamic
{
	enum tag TAG;
	union{
	   bool b;
           int i;
           float f;
	};
};	

int main()
{
	struct dynamic d;
	printf("the size of struct is %d\n", sizeof(d));
	d.TAG = TAG_FLOAT;
	d.f = 42.124;
	return 0;
}


