#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// this way of doing is not efficient. you need to pass too many arguments and if you are putting this in a library to be used by an 
// end user, he is not going to have an idea about what to pass and what they mean without documentation. 
// the ideal way of solving this is using bit flags. 

typedef unsigned int t_flags;
#define FLAG_A (1<<0) // 1
#define FLAG_B (1<<1) // 2
#define FLAG_C (1<<2) // 4

int f2(int x, t_flags flags)
{
    if (flags & FLAG_A)
    {
	x += x;
    }
    if (flags & FLAG_B)
    {
        x *= x;
    }
    if (flags & FLAG_C)
    {
	x = ~x;
    }
    return x;
}

int f(int x, bool to_add, bool to_square, bool to_not)
{
    if (to_add)
        x+=x;
    if (to_square)
        x *= x;
    if (to_not)
        x = ~x;
    return x;    
}

int main()
{
    int x = 6;
    printf("%d\n", f(x, 1,0,0));
    printf("%d\n", f2(6, FLAG_A));
    printf("%d\n", f2(8, FLAG_B | FLAG_C));
    return 0;
}


