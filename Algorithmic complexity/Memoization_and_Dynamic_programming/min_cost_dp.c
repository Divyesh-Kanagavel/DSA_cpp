/* the same min_cost problem now solved with the help of dynamic programming */
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

void solve_k(int num[], double price[], int num_schemes, double unit_price,double memo[])
{
    double best, result;
    int i,j;
    /* base condition for dp */
    memo[0] = 0;
    for(i=1;i<=SIZE;++i)
    {
        result = memo[i-1];
        best = result + unit_price;
        for (j=0;j<num_schemes;++j)
        {
            if ((i-num[j]) >= 0)
            {
                result = memo[i-num[j]];
                best = min(best,result + price[j]);
            }
        }
        memo[i] = best;
    }
}

double solve(int num[], double price[], int num_schemes, double unit_price, int num_items, double memo[])
{
    double best;
    int i;
    solve_k(num, price, num_schemes, unit_price, memo);
    best = memo[num_items];
    for(i=num_items+1; i<SIZE;++i)
        best = min(best, memo[i]);

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