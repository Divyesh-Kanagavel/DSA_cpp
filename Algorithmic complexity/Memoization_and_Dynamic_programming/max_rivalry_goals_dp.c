/*
Our task is to determine the maximum number of goals 
that could have been scored in rivalry games.
*/
#include <stdio.h>

/*
the problem can be solved recursively.
Option 1: start from game n for both the teams, if it is a rivalry game,
add the sum of goals and recurse with n-1 for both the teams
Option 2 : n,n is not a rivalry game, so we move to n-1, n-1.
Option 3 : n,n is not a rivalry game, so we move to n-1, n.
Option 4 : n,n is not a rivalry game, so we move to n, n-1.
This way all possibilies are covered and hence the solution is obtained.asm
Base condition is if number of games for either teams is 0, return 0
*/
#define SIZE 1000
int max(int v1, int v2)
{
    if (v1 > v2)
        return v1;
    else
        return v2;
}

int solve(char outcome1[], char outcome2[], int goals1[], int goals2[],
            int n)
{
    int i,j, first, second, third, fourth;
    static int dp[SIZE+1][SIZE+1];

    /*if number of hawks or geese games is zero, then that index in dp corresponds to zero*/
    for(i=0; i<=n; ++i)
    {
        dp[0][i] = 0;
    }

    for(i=0; i<=n; ++i)
    {
        dp[i][0] = 0;
    }
    
    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=n; ++j)
        {
            if ((outcome1[i] == 'W' && outcome2[j] == 'L' && goals1[i] > goals2[j]) || 
            (outcome1[i] == 'L' && outcome2[j] == 'W' && goals1[i] < goals2[j]))
                first = dp[i-1][j-1] + goals1[i] + goals2[j];
            else
                first = 0;
    
            second = dp[i-1][j-1];
            third = dp[i-1][j];
            fourth = dp[i][j-1];
            dp[i][j] =  max(first, max(second, max(third, fourth)));
        }
    }
    return dp[n][n];
}

int main()
{
    int i, j, n, result;
    char outcome1[SIZE+1], outcome2[SIZE+1];
    int goals1[SIZE+1], goals2[SIZE+1];

    scanf("%d ", &n);
    for(i=1;i<=n;++i)
        scanf("%c", &outcome1[i]);
    for(i=1;i<=n;++i)
        scanf("%d ", &goals1[i]);
    for(i=1;i<=n;++i)
        scanf("%c", &outcome2[i]);
    for(i=1;i<=n;++i)
        scanf("%d ", &goals2[i]);
 
    result = solve(outcome1, outcome2, goals1, goals2, n);

    printf("%d\n", result);

    return 0;    
}