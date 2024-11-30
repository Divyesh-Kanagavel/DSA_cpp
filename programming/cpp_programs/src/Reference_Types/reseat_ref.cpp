#include <cstdio>

int main()
{
	int original = 100;
	int &original_ref = original;
	printf("original = %d\n", original);
	printf("original_ref = %d\n", original_ref);
	int new_value = 200;
	original_ref = new_value;
	printf("original = %d\n", original);
	printf("original ref = %d\n", original_ref);
	return 0;
}
