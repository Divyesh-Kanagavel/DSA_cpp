/* shell sort to sort an array of integers */

#include <stdio.h>
void shellsort(int n, int v[])
{
    int i,j,gap,temp;
    for (gap=n/2; gap>0; gap/=2) // outer loop
    {
        for (i=gap; i<n; i++)
        {
            for(j=i-gap;j>=0 && v[j] > v[j+gap]; j-=gap)
            {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;  
            }
        }
    }
}

int main(void)
{
    int v[] = {4,14,2,15,10,9,55};
    shellsort(sizeof(v)/sizeof(v[0]),v);
    for(int i=0;i<sizeof(v)/sizeof(v[0]);i++)
    {
        printf("%d\t", v[i]);
    }
    printf("\n");
    return 0;
}