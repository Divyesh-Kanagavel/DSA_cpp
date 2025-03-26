/*the same max_burgers is solved now using dynamic programming. 
in the memoization approach, we used recursion but cached already visited values
and this it saved us many recursion calls. Dynamic programming here eliminates the need 
for recursion. the problem is organized such that at any given time, when we want to compute a value, we break 
it down into subproblems whose values we already know. this way there is no need to call recursion. Our subproblems solutions are
cached already. */

#include <stdio.h>

#define SIZE 10000

int max(int v1, int v2)
{
    if (v1 > v2)
        return v1;
    else
        return v2;
}

void solve(int m, int n, int t)
{
    int dp[SIZE];

    dp[0] = 0;

    int result, first, second, i;
    
    for(i=1;i<=t;++i)
    {
        if (i >= m)
            first = dp[i-m];
        else
            first = -1;
        
        if (i >=n)
            second = dp[i-n];
        else
            second = -1;
        
        if (first == -1 && second == -1)
            dp[i] = -1;      
        else
            dp[i] = max(first, second) + 1;
    }
    result = dp[t];
    if (result >= 0)
    {
        printf("%d\n", result);
    }
    else
    {
        i = t - 1;
        result = dp[i];
        while(result == -1)
        {
            i--;
            result = dp[i];         
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