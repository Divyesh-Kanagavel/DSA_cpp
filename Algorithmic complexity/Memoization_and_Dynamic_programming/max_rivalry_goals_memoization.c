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
            int i, int j, int memo[SIZE+1][SIZE+1])
{
    int first, second, third, fourth;
    if (memo[i][j]!=-1)
        return memo[i][j];
    if (i==0 || j==0)
    {
        memo[i][j] = 0;
        return memo[i][j];
    }
    
    if ((outcome1[i] == 'W' && outcome2[j] == 'L' && goals1[i] > goals2[j]) || 
        (outcome1[i] == 'L' && outcome2[j] == 'W' && goals1[i] < goals2[j]))
        first = solve(outcome1, outcome2, goals1, goals2, i-1, j-1,memo) + goals1[i] + goals2[j];
    else
        first = 0;
    
    second = solve(outcome1, outcome2, goals1, goals2, i-1, j-1,memo);
    third = solve(outcome1, outcome2, goals1, goals2, i-1, j,memo);
    fourth = solve(outcome1, outcome2, goals1, goals2, i, j-1,memo);

    memo[i][j] =  max(first, max(second, max(third, fourth)));
    return memo[i][j];
}

int main()
{
    int i, j, n, result;
    char outcome1[SIZE+1], outcome2[SIZE+1];
    int goals1[SIZE+1], goals2[SIZE+1];
    static int memo[SIZE+1][SIZE+1]; /* static variable since it consumes a lot of space*/
    scanf("%d ", &n);
    for(i=1;i<=n;++i)
        scanf("%c", &outcome1[i]);
    for(i=1;i<=n;++i)
        scanf("%d ", &goals1[i]);
    for(i=1;i<=n;++i)
        scanf("%c", &outcome2[i]);
    for(i=1;i<=n;++i)
        scanf("%d ", &goals2[i]);

    /*populate memo with -1s*/
    for(i=0;i<SIZE+1;++i)
    {
        for(j=0;j<SIZE+1;++j)
        {
            memo[i][j] = -1;
        }
    }
    
    result = solve(outcome1, outcome2, goals1, goals2, n, n, memo);

    printf("%d\n", result);

    return 0;    
}