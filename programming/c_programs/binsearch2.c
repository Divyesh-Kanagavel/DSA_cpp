/* binary search with single test condition inside loop*/

/* binsearch : binary search algorithm  */
#include <stdio.h>
#include <time.h>

//binsearch with one test condition inside loop
int binsearch2(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n-1;
    while(low <= high)
    {
        mid = (low+high)/2;
        if (x < v[mid])
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    if (x == v[mid])
    {
        return mid;
    }
    else
    {
        return -1;
    }

}

// binsearch with two test conditions inside loop
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n-1;
    while(low <= high)
    {
        mid = (low+high)/2;
        if (x < v[mid])
        {
            high = mid-1;
        }
        else if (x > v[mid])
        {
            low = mid+1;
        }
        else
        {
            return mid; // element found
        }
    }
    return -1; // element not found
}
int main(void)
{
    int v[] = {3,4,5,6,14,19,23,90}; // sorted array
    int n = sizeof(v)/sizeof(v[0]);
    printf("size = %d\n",n);
    int elem = 14;
    clock_t begin = clock();
    int index = binsearch(elem,v,n);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("index = %d\n", index);
    printf("runtime of binsearch : %lf\n", time_spent);
    begin = clock();
    int index2 = binsearch2(elem,v,n);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("index2 = %d\n", index2);
    printf("runtime of binsearch2 : %lf\n", time_spent);
}

//observation:
/* the second function binsearch2 which has just one test inside loop is consistenly faster by atleast two times 
 in the runtime tests ran.*/