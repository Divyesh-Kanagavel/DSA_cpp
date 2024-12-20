/* in an array, find two elements whose sum is closest to zero*/

#include <cstdio>
#include <algorithm>
#define INF 100000

// method 1 : brute force approach -> time complexity O(n^2), space complexity : O(1)
int findSumZero(int arr[], int size)
{
    int i,j;
    int sum;
    int minSum = INF;
    int minFirst = 0;
    int minSecond = 0;
    for (i=0;i<size;i++)
    {
        for (j=i+1;j<size;j++)
        {
            sum = arr[i] + arr[j];
            if (abs(sum) < minSum)
            {
                minSum = abs(sum);
                minFirst = i;
                minSecond = j;
            }
        }
    }
    printf("the minsum is %d and the operands are %d and %d\n", minSum, arr[minFirst], arr[minSecond]);
    return 0;
}

// method 2 : sort the array and then find the sum of two elements closes to zero
// time complexity : O(nlogn), space complexity : O(1)
int findSumZero2(int arr[], int size)
{
    std::sort(arr, arr+size);
    int start = 0;
    int end = size-1;
    int sum;
    int minsum = INF;
    int minFirst = 0;
    int minSecond = size-1;
    while(start < end)
    {
        sum = arr[start] + arr[end];
        if (abs(sum) < minsum)
        {
            minsum = abs(sum);
            minFirst = start;
            minSecond = end;
        }
        if (sum < 0)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    printf("the minsum is %d and the operands are %d and %d\n", minsum, arr[minFirst], arr[minSecond]);
    return 0;

}

int main()
{
    int arr[] = {3,5,-2,9,-7,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = findSumZero2(arr, n);
    return 0;
}