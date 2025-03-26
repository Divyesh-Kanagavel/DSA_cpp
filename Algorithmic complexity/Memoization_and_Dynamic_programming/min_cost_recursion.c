/*
You want to buy apples, so you go to an apple store.
The store has a price for buying one apple—for example, $1.75. 
The store also has m pricing schemes, where each pricing scheme gives a number n and a price p for buying n apples.
For example, one pricing scheme might state that three apples cost a total of $4.00.
another might state that two apples cost a total of $2.50. 
You want to buy at least k apples and to do so as cheaply as possible.
UVa problem 10980
*/

#include <stdio.h>

/*recursion approach of splitting pronlem into sub-problem. this is similar to 
max_burgers problem but the objective is minimization and instead of two 
sub problems, we have an array of possible sub-problems*/
#define SIZE 200
/*minimum computation function */
double min(double x1, double x2)
{
    if(x1<x2)
        return x1;
    else
        return x2;
}

double solve_k(int num[], double price[], int num_schemes, double unit_price, int k)
{
    double best, result;
    int i;
    /*if number of apples to buy is 0, return 0 rupees*/
    if (k==0)
        return 0;
    else
    {
        result = solve_k(num, price, num_schemes, unit_price, k-1);
        best = result + unit_price;
        for(i=0;i<num_schemes;++i)
        {
            if ((k-num[i]) >= 0)
            {
                result = solve_k(num, price, num_schemes, unit_price, k-num[i]);
                best = min(best, result + price[i]);
            }
        }

        return best;
    }  
    
}

/*the problem says we can buy at least k apples. which means if there is a possibility
of buying more at cheaper price, I am going for it*/
/* so after computation of best for k , we check k+1,k+2 and so on.
The limit on new model is the maximum number of pricing apples per pricing scheme which is 100*/

double solve(int num[], double price[], int num_schemes, double unit_price, int k)
{
    double best;
    int i;
    best = solve_k(num, price, num_schemes, unit_price, k);
    for(i=k+1; i<SIZE;++i)
        best = min(best, solve_k(num, price, num_schemes, unit_price, i));

    return best;
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

#define MAX_SCHEMES 20

int main()
{
    int test_case, num_schemes, num_items, more,i;
    double price[MAX_SCHEMES];
    int num[MAX_SCHEMES];
    double unit_price, result;
    test_case = 0;

    while(scanf("%lf%d", &unit_price, &num_schemes)!=-1)
    {
        ++test_case;
        for(i=0;i<num_schemes;++i)
        {
            scanf("%d%lf",&num[i], &price[i]);
        }
        scanf(" ");
        printf("Case %d:\n", test_case);
        more = get_number(&num_items);
        while(more)
        {
            result = solve(num, price, num_schemes, unit_price, num_items);
            printf("Buy %d for $%.2lf\n", num_items, result);
            more = get_number(&num_items);
        }
        /* calculate the best for last number */
        result = solve(num, price, num_schemes, unit_price, num_items);
        printf("Buy %d for $%.2lf\n", num_items, result);        

    }
    return 0;
}

