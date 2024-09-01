/* an enumeration is a list of integer constant values */
#include <stdio.h>

enum boolean {FALSE, TRUE};

// unless explicitly specified, they have values starting from 0 and increasing progressively.
// if not all values are specified, unspecified values continue from the last specified value.

enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n', VTAB = '\v', RETURN = '\r'};


int main(void)
{
    enum boolean e;
    e = 23; // it is not in defined in boolean enum. compiler need not check if it is defined. it will simply print as 21.
    printf("%d\n", e);
}