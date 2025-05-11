#include <stdio.h>

int can_make_min_distance(int distance, int rocks[], int num_rocks,
int num_remove, int length)
{
    int i;
    int cur_rock_pos;
    int prev_rock_pos = 0, removed = 0;
    if (length < distance)
        return 0;
    for(i=0;i<num_rocks;i++)
    {
        cur_rock_pos = rocks[i];
        if (cur_rock_pos - prev_rock_pos < distance)
        {
            removed++;
        }
        else
        {
            prev_rock_pos = cur_rock_pos;
        }
    }
    if(length - prev_rock_pos < distance)
    {
        removed++;
    }
    return removed <= num_remove;
}
/* solve for min jump distance using binary search
the invariant here is anything with and below low are feasible
 and anything with high or more are infeasible.*/
void solve(int rocks[], int num_rocks, int num_remove, int length)
{
    int low, mid, high;
    low = 0;
    high = length + 1; /* keeping high as length disturbs the invariant in edge case of jumping from start position to the river bed length with allrocks removed*/
    while (high-low > 1)
    {
        mid = (low + high)/2;
        if (can_make_min_distance(mid, rocks, num_rocks, num_remove, length))
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    printf("%d\n",low);
}
#define MAX_ROCKS 50000

int compare(const void* a, const void* b)
{
    int num1 = *(const int*)a;
    int num2 = *(const int*)b;
    return num1-num2;
}
int main(void)
{
    /* reading the input */
    static int rocks[MAX_ROCKS];
    int length, num_rocks, num_remove, i;
    scanf("%d%d%d", &length, &num_rocks, &num_remove);
    for(i=0;i<num_rocks;i++)
    {
        scanf("%d",&rocks[i]);
    }
    qsort(rocks, num_rocks, sizeof(int),compare);
    solve(rocks, num_rocks, num_remove, length);
}