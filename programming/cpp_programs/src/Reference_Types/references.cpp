#include <cstdio>

int main()
{
	// reference are safer than pointers, cannot be assigned to null easily and cannot be reseated [reassigned]. there are pros and cons for both
	int a = 4;
	int &b = a;
	printf("value=%d, address=%p\n",a,&a);
	printf("value=%d, address=%p\n",b,&b);
	return 0;
}
