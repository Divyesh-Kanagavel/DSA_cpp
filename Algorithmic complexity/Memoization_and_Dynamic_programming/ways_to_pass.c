/* uva problem 10910 
Passing a course requires at least p marks. (p isn’t necessarily 50 or 60 or whatever is needed in school; 
it could be any positive integer.) A student took n courses and passed them all.
Adding up all of the student’s marks in these n courses gives a total of t marks that the student earned,
but we don’t know how many marks the stu- dent earned in each course.
So we ask the following: in how many distinct ways could the student have passed all of the courses?
*/

#include <stdio.h>
#define SIZE 70

int solve(int n, int t, int p, int memo[SIZE+1][SIZE+1])
{
    int i, total,m;
    if (memo[n][t]!=-1)
        return memo[n][t];
    if (n==0 && t==0) /* reached the base case of no courses left and no total marks left*/
    {
        memo[n][t] = 1;
        return memo[n][t];
    }
    if (n==0) /* no courses left but total marks still not zero -> implies not the right candidate*/
    {
        memo[n][t] = 0;
        return memo[n][t];
    }
    
    total=0;
    for(m=p; m<=t;++m)
    {
        total += solve(n-1,t-m,p,memo);
    }
    memo[n][t] = total;
    return memo[n][t];
}

int main()
{
    int i, x,y, n, p, t, k;
    static int memo[SIZE+1][SIZE+1];
    scanf("%d", &k); /* number of test cases*/
    for(i=0;i<k;++i)
    {
        scanf("%d%d%d", &n,&t,&p); /* n is the number of courses, t is the total marks, p is the pass mark*/
        for(x=0;x<=SIZE;++x) /* be careful with edge cases, not having <= added bugs in testing*/
        {
            for(y=0;y<=SIZE;++y)
            {
                memo[x][y] = -1;
            }
        }
        printf("%d\n", solve(n,t,p,memo));
    }
    return 0;
}