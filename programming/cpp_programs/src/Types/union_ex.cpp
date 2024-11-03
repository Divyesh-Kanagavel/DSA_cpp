#include <cstdio>
#include <cstring>
union variant
{
	char str[10];
	int integer;
	float floating_pt;
};


int main()
{
	variant v;
	printf("the size of variant is %d\n",sizeof(v));
	v.integer = 10;
	printf("elements of v : %s, %d, %f\n", v.str,v.integer,v.floating_pt);
	memcpy(v.str, "hello", 5);
	printf("elements of v : %s, %d, %f\n", v.str,v.integer,v.floating_pt);
	v.floating_pt = 4.31;
	printf("elements of v : %s, %d, %f\n", v.str,v.integer,v.floating_pt);
	return 0;
}
