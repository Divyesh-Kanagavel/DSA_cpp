#include <cstdio>

int main()
{
	auto original = 100;
	auto &original_ref = original;
	printf("original = %d\n", original);
	printf("original_ref = %d\n", original_ref);
	auto new_value = 200;
	original_ref = new_value;
	printf("original = %d\n", original);
	printf("original ref = %d\n", original_ref);
	return 0;
}