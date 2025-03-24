#include <stdio.h>

/* in the solution using just recursion, we see a staggering number of 
calls made repeatedly when for t, you may have to call a max of t or t-1 times. 
instead every number from t to 1 are called many times over and over leading to an 
exponential time complexity. Memoization works on the principle, remember not refigure.*/

#define SIZE 10000

int max(int v1, int v2)
{
    if (v1 > v2)
        return v1;
    else
        return v2;
}
int solve_t(int m, int n, int t, int memo[])
{
    int first, second;
    if (memo[t]!=-2)
        return memo[t]; /*if value already cached in memo, return the value*/
    if (t == 0)
    {
        memo[t] = 0;
        return memo[t];
    }

    if (t >= m)
    {
        first = solve_t(m, n, t-m, memo);
    }
    else
    {
        first = -1;
    }

    if (t>=n)
    {
        second = solve_t(m , n, t-n, memo);
    }
    else
    {
        second = -1;
    }

    if (first == -1 && second == -1)
    {
        memo[t] = -1;
        return memo[t];
    }
    else
    {
        memo[t] = max(first, second) + 1;
        return memo[t];
    }
}
void solve(int m, int n, int t)
{
    int memo[SIZE];
    
    int result,i;
    for(i=0;i<SIZE;++i)
    {
        memo[i] = -2;
    }
    result = solve_t(m,n,t,memo);
    if (result >= 0)
    {
        printf("%d\n", result);
    }
    else
    {
        i = t - 1;
        result = solve_t(m,n,i,memo);
        while(result == -1)
        {
            i--;
            result = solve_t(m,n,i, memo);           
        }
        printf("%d %d\n", result, t-i);
    }
}

int main()
{
    int m,n,t;
    while(scanf("%d%d%d", &m,&n,&t)!=-1)
    {
        solve(m,n,t);
    }
    return 0;
}
/*with memoization, we drastically reduce the number of function cals and thus help 
solve the problem in linear time complexity. all test cases are passed .*/