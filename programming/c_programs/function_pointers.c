#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIMPLE_EXAMPLE 1

// alias for function pointer

typedef int (*my_func)(int,int);

int foo(int x, int y)
{
    return x+y;
}

bool p(int x)
{
    return (x%2 == 0);
}

int compar(const void* a,const  void* b)
{
    return *(int *)a - *(int *)b;
}

void printif(int xs[], bool (*predicate)(int))
{
    for(int i=0;i<10;i++)
    {
        if (predicate(xs[i]))
        {
            printf("%d\n", xs[i]);
        }
    }
}

int main()
{
#if SIMPLE_EXAMPLE
    // function pointer syntax : return_type (*name_func) (*args)
    int (*f)(int , int) = foo;
    printf("%d\n", f(5,6));
    my_func f2 = foo;
    printf("%d\n", f2(4,2));
#else
    int xs[] = {3,4,1,9,18,0,15,6,10,21};
    //printif(xs, p);
    printf("before sorting\n");
    for(int i=0;i<10;i++)
    {
        printf("%d ", xs[i]);
    }
    printf("\n");

    qsort(xs,10,sizeof(int), compar);
    printf("after sorting\n");
    for(int i=0;i<10;i++)
    {
        printf("%d ", xs[i]);
    }
    printf("\n");




#endif
    return 0;
}

