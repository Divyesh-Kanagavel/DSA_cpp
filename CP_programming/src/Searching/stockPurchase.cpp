/*Given an array, whose nth element is the price of the stock on nth day. You are asked to buy once and sell once, on what date you will be buying and at what date you will be selling to get maximum profit.*/

#include <cstdio>

// method 1 : brute force approach -> two loops to find maximum of difference of two elements
// time complexity : O(n^2) and space complexity : O(1)
void maxProfit(int arr[], int size)
{
    int i,j;
    int max;
    int buy=0,sell=0;
    for(i=0;i<size;i++)
    {
        for (j=i+1;j<size;j++)
        {
            if ((arr[j]-arr[i]) > max)
            {
                max = arr[j]-arr[i];
                buy = i;
                sell = j;
            }
        }
    }

    printf("maxProfit = %d, buy at %d and sell at %d\n",max, arr[buy],arr[sell]);
}

// method 2 : more clever solution -> keep track of minimum element to maximize difference
// time complexity : O(n) and space complexity : O(1)
void maxProfit2(int arr[], int size)
{
    int min = 0;
    int max = 0;
    int buy = 0;
    int sell = 0;
    int profit = 0;
    for(int i=0;i<size;i++)
    {
        if (arr[i] < arr[min])
        {
            min = i;
        }
        profit = arr[i] - arr[min];
        if(profit > max)
        {
            max = profit;
            buy = min;
            sell = i;
        }
    }
    printf("maxProfit = %d, buy at %d and sell at %d\n",max, arr[buy],arr[sell]);
}

int main()
{
    int arr[]= {100,400,300,900,150,600,450};
    int n = sizeof(arr)/sizeof(arr[0]);
    maxProfit2(arr,n);
}