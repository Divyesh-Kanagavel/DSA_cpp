#include <stdio.h>
#include <stdint.h>

enum FOO
{
	foo_1,
	foo_2,
	foo_3
};
// usual way of array initialization
int xs[] = {4,9,16};

// lookup table way of array initialization
int ys[] = {
	[foo_1] = 4,
	[foo_2] = 9,
	[foo_3] = 16
};

char convert[] = {
	['a'] = 'A',
	['b'] = 'B',
	['e'] = 'E'
};
int main()
{
	// usual way of accessing array
	printf("%d %d %d\n", xs[0],xs[1],xs[2]);
	
	printf("%d %d %d\n", ys[foo_1],ys[foo_2],ys[foo_3]);
	printf("%c, %c, %c\n", convert['a'], convert['b'], convert['e']);
	return 0;
}
