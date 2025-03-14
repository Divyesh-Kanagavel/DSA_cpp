#include <stdio.h>
#include <stdlib.h>

int identical_right(int snow1[], int snow2[], int start)
{
    for(int offset = 0; offset < 6; ++offset)
    {
        if (snow1[offset]!=snow2[(start+offset)%6])
            return 0;
    }
    return 1;
}

int identical_left(int snow1[], int snow2[], int start)
{
    int snow2_index;
    for(int offset=0;offset<6;++offset)
    {
        snow2_index = start - offset;
        if (snow2_index < 0)
            snow2_index = snow2_index + 6;
        if (snow1[offset]!=snow2[snow2_index])
            return 0;
    }
    return 1;
}
int are_identical(int snow1[], int snow2[])
{
    int start;
    for(start=0;start<6;++start)
    {
        if (identical_right(snow1, snow2, start))
            return 1;
        if (identical_left(snow1, snow2, start))
            return 1;            
    }
    return 0;
}
/* a naive comparison function for sorting 
if two elements are same , return 0, if first differing element of s1 is smaller
than s2 , return -1 else return 1*/
int compare(const void* snow1, const void* snow2)
{
    int i;
    const int* s1 = snow1;
    const int* s2 = snow2;

    if (are_identical(s1, s2))
        return 0;

    for (i=0;i<6;++i)
    {
        if (s1[i]<s2[i])
            return -1;
    }
    return 1;
}
/* this may not work in all cases though is a more efficient that the 
O(n^2) approach before. this is because of the way comparisons are done 
for sorting. 
Due to the transitive property of the comparisons, even before comparing
every pair, the sort function may make assumptions and set -1 or 1
As expected , when submitted in dmoj, it passes 16/25 test cases.
*/
void identify_identical(int snowflakes[][6], int n)
{
    int i;
    qsort(snowflakes, n, 6*sizeof(int), compare);
    for(i=1;i<n;++i)
    {
        if (are_identical(snowflakes[i-1], snowflakes[i]))
        {
            printf("Twin snowflakes found.\n");
            return;
        }
    }
    printf("No two snowflakes are alike.\n");
}

#define SIZE 100000
// Reading the input
int main()
{
    static int snowflakes[SIZE][6];
    int n, i, j;
    scanf("%d", &n);
    for (i=0;i<n;++i)
    {
        for(j=0;j<6;++j)
        {
            scanf("%d",&snowflakes[i][j]);
        }        
    }
    identify_identical(snowflakes, n);
    return 0;
}