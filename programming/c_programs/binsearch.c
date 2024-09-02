/* binsearch : binary search algorithm  */
#include <stdio.h>

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
    int v[] = {3,4,5,6,19,90,23,14};
    int n = sizeof(v)/sizeof(v[0]);
    int elem = 21;
    int index = binsearch(elem,v,n);
    printf("index = %d\n", index);
}