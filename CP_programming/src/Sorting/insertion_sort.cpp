#include <cstdio>

/*
Notes:
1. Worst time complexity : O(n^2)
2. Average time complexity : O(n^2)
3. Space complexity : O(1)
4. Best complexity : O(n)
5. Stable sort : true
There are lesser number of swaps and this write operations in insertion sort
and thus they are faster when run in systems. 
*/
void insertionSort(int arr[], int size)
{
    for (int i=1;i<size;i++)
    {
        int temp = arr[i];
        int j;
        for (j=i; j>0 && (arr[j-1] > temp); j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}

int main()
{
    int arr[] = {4,10,13,7,1,0,19};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, size);
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}