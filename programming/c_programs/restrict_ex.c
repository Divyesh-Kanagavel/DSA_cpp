#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
// difference between restrict and non-restrict is seen in -O3 optimization flag
// the assembly code generated has fewer instructions compared to without restrict
// in the case without restrict, the value c is copied to register rdx and that is added to rdi which holds a
// again rdx is loaded with c and then is added to a. 
// when restrict is added, the rdx is not loaded again with c, instead it uses the pre-loaded c.
// but if you pass &a, &b and & a again in place of &c, it will not give desired results with restrict because of this optimization.
void update_ptrs(size_t *a, size_t *b, size_t *c)
{

	*a += *c;
	*b += *c;
}

void update_ptrs_restrict( size_t* restrict a,  size_t* restrict b,size_t* restrict c)
{
	*a += *c;
	*b += *c;
}

int main()
{
	size_t a=1;
	size_t b=2;
	size_t c=3;
	printf("init : a=%d,b=%d,c=%d\n",a,b,c);
	update_ptrs(&a,&b,&c);
	printf("after update_ptrs : a=%d,b=%d,c=%d\n",a,b,c);
	a=1;b=2;c=3;
	update_ptrs_restrict(&a,&b,&c);
	printf("after update_ptrs_restrict : a=%d,b=%d,c=%d\n",a,b,c);
	return 0;
}

