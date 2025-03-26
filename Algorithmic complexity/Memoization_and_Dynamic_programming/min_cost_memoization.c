/* the same min_cost problem now solved with the help of memoization */
#include <stdio.h>
#define SIZE 200
/*minimum computation function */
double min(double x1, double x2)
{
    if(x1<x2)
        return x1;
    else
        return x2;
}

int get_number(int* num)
{
    int ch;
    int ret = 0;
    ch = getchar();
    while(ch!=' ' && ch!='\n')
    {
        ret = ret * 10 + ch - '0';
        ch = getchar();
    }
    *num = ret;
    return ch == ' ';
}

double solve_k(int num[], double price[], int num_schemes, double unit_price, int num_items, double memo[])
{
    double best, result;
    int i;
    if (memo[num_items]!=-1)
        return memo[num_items]; /* early return if num_items already populated in memo */
    if (num_items == 0)
    {
        memo[num_items] = 0;
        return memo[num_items]; /* base recursion condition */
    }
    else
    {
        result = solve_k(num, price, num_schemes, unit_price, num_items-1, memo); /* solve for num_items-1 */
        best = result + unit_price; /* initialize best with result for num_items-1 + unit_price */
        for(i=0;i<num_schemes;++i)
        {
            if ((num_items-num[i])>=0)
            {
                /* update best based on result for num_items - num[i] */
                result = solve_k(num, price, num_schemes, unit_price, num_items-num[i], memo);
                best = min(best, result + price[i]);
            }
        }
        memo[num_items] = best;
        return memo[num_items];
    }
}

double solve(int num[], double price[], int num_schemes, double unit_price, int num_items, double memo[])
{
    double best;
    int i;
    best = solve_k(num, price, num_schemes, unit_price, num_items, memo);
    for(i=num_items+1; i<SIZE;++i)
        best = min(best, solve_k(num, price, num_schemes, unit_price, i,memo));

    return best;
}


#define MAX_SCHEMES 20
int main(void)
{
    int test_case, num_schemes, num_items, more, i;
    double unit_price, result;
    int num[MAX_SCHEMES];
    double price[MAX_SCHEMES];
    double memo[SIZE];
    test_case = 0;

    while(scanf("%lf%d", &unit_price, &num_schemes)!=-1)
    {
        ++test_case;
        for(i=0;i<num_schemes;++i)
        {
            scanf("%d%lf", &num[i], &price[i]);
        }
        scanf(" ");
        printf("Case %d:\n", test_case);
        for(i=0;i<SIZE;++i)
        {
            memo[i] = -1;
        }
        more = get_number(&num_items);
        while(more)
        {
            result = solve(num, price, num_schemes, unit_price, num_items, memo);
            printf("Buy %d for $%.2f\n", num_items, result);
            more = get_number(&num_items);
        }
        result = solve(num,price, num_schemes,unit_price, num_items,memo);
        printf("Buy %d for $%.2lf\n", num_items, result);
    }
    return 0;
}