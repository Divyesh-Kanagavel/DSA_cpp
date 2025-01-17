#include <cstdio>

/*
Notes:
1. Worst time complexity : O(nlogn)
2. Average time complexity : O(nlogn)
3. Best time complexity : O(nlogn)
4. Space complexity : O(n)
5. Stable sort : True
how O(nlogn) ?-> T(n) = 2 * T(n/2) + O(n) [for merging]
log_a (b) = log_2 (2) = 1 -> O(nlogn)
*/

void merge(int arr[], int tempArray[], int lowerIndex, int upperIndex, int middleIndex)
{
    int lowerStart = lowerIndex;
    int lowerStop = middleIndex;
    int upperStart = middleIndex + 1;
    int upperStop = upperIndex;
    int count = lowerIndex;
    while((lowerStart <= lowerStop) && (upperStart <= upperStop))
    {
        if (arr[lowerStart] < arr[upperStart])
        {
            tempArray[count++] = arr[lowerStart++];
        }
        else
        {
            tempArray[count++] = arr[upperStart++];
        }
    }
    while((lowerStart <= lowerStop))
    {
        tempArray[count++] = arr[lowerStart++];
    }
    while((upperStart <= upperStop))
    {
        tempArray[count++] = arr[upperStart++];
    }

    for(int i=lowerIndex; i<=upperIndex;i++)
    {
        arr[i] = tempArray[i];
    }
}

void mergeSrt(int arr[], int tempArr[], int lowerIndex, int upperIndex)
{
    if (lowerIndex >= upperIndex)
        return;
    
    int middleIndex = (lowerIndex + upperIndex)/2;
    mergeSrt(arr, tempArr, lowerIndex,middleIndex);
    mergeSrt(arr, tempArr, middleIndex+1, upperIndex);
    merge(arr, tempArr, lowerIndex, upperIndex, middleIndex);

}

void mergeSort(int arr[], int size)
{
    int *tempArr = new int[size];
    mergeSrt(arr, tempArr, 0, size-1);
}


int main()
{
    int arr[] = {4,10,13,7,1,0,19};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, size);
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}