/*
A man named Homer Simpson likes to eat and drink. He has t minutes that he’ll spend eating burgers and drinking beer.
 There are two kinds of burgers. One of them takes m minutes to eat, and the other takes n minutes
to eat.Homer likes burgers more than beer, so he’d like to spend the entire t minutes eating burgers. 
However, doing so isn’t always possible. For example, if m = 4, n = 9, and t = 15, then no combination of the 4-minute and 9-minute burgers can take him exactly 15 minutes to eat. 
If that’s the case, he’ll spend as much time as possible eating burgers and then fill the rest of the time drinking beer. 
Our task is to determine the number of burgers that Homer can eat.
*/

/* if we are able to find number of burgers whose eating time is exactly equal to t minutes,problem solved
if not, we try to check t-1 minutes and keep moving downward till we find the right time */
#include <stdio.h>
int max(int v1, int v2)
{
    if  (v1 > v2)
        return v1;
    else
        return v2;
}
/* case where exactly t minutes can be spent eating burgers*/
int solve_t(int m, int n, int t)
{
    /* base recursion condition */
    if (t==0)
        return 0;
    
    int first,second;
    
    if (t >= m)
        first = solve_t(m,n,t-m);
    else
        first = -1;
    
    if (t >= n)
        second = solve_t(m, n, t-n);
    else
        second = -1;
    
    if (first == -1 && second == -1)
        return -1;
    else
        return max(first, second) + 1;
}

/* case where exactly t minutes cannot be used to eat only burgers, we look for solution in t-1, t-2  etc*/
void solve(int m, int n, int t)
{
    int result, i;
    result = solve_t(m,n,t);
    if (result >= 0)
    {
        printf("%d\n", result);
    }
    else
    {
        i = t - 1;
        result = solve_t(m,n,i);
        while(result == -1)
        {
            i--;
            result = solve_t(m,n,i);
        }
        printf("%d %d\n", result, t-i);
    }
}

int main()
{
    /* read the inputs*/
    int m,n,t;
    while(scanf("%d%d%d", &m,&n,&t)!=-1)
    {
        solve(m,n,t);
    }
    return 0;
}
/* with this recursion, we see that the code solves the problem, but time limit is 
exceeded. we need to reduce the recursion calls for better time complexity*/