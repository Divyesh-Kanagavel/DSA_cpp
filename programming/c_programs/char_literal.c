#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Difference between char_array and char_literal
char_literal : stored in memory as a string , but stored in a separate compartment called .rodata which is readonly
In order to modify its value, need to duplicate it using strdup which places an equivalent string in heap
char_array : stored as string and is modifiable since it is stored in stack or data or gss.
 */

int main()
{
	char array[] = "I am a char array";
	char *literal = "I am a string literal";
	char *s = strdup(literal);
        s[0] = 'U';
	array[0] = 'U';
	printf("%s\n", array);
	printf("%s\n",s);
	return 0;
}

