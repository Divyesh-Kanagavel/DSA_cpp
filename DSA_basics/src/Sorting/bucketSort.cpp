#include <cstdio>

/* bucket sort : 
Requirement : 
the data should be in a pre-defined range
*/

/*
Notes: 
1. Average,best time complexity : O(n+k)
2. Worst time complexity : O(n^2) - this happens when you have floating point numbers
and a few buckets : all numbers fall in same bucket - then you use sorting algos like insertion sort or merge which take O(n^2) or O(nlogn)*/

/*
Generalized bucket sort : you will sometimes have elements in a range being put into bucket instead of unique values
For example : alphabets a,b,c,d might be your buckets and these will have a pointer to words starting from these letters. the words can be kept sorted using insertion sort or some other algorithm
*/

void bucketSort(int arr[], int size, int range_low, int range_high)
{
    int range = range_high - range_low + 1;
    int* buckets  = new int[range];

    for(int i=0;i<range;i++)
    {
        buckets[i] = 0;
    }

    for(int i=0;i<size;i++)
    {
        buckets[arr[i]]++;
    }
    int j=0;

    for(int i=range_low;i<=range_high;i++)
    {
        for(;buckets[i]>0;buckets[i]--)
        {
            arr[j++] = i;
        }
    }
    delete[] buckets;
    return;
}

int main()
{
    int arr[] = {0,4,1,5,8,2,0,9}; // range 0-9 => k = 10
    int size = sizeof(arr)/sizeof(arr[0]);
    int range_low = 0;
    int range_high = 9;
    bucketSort(arr, size, range_low, range_high);
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}