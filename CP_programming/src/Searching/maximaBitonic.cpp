/* find maxima in bitonic array -> contains increasing sequence of integers and then decreasing sequence of integers*/

#include <cstdio>

// method : use an algorithm similar to binary search to reduce search space by half and find maxima eventually
// at mid point, check if sequence is increasing or decreasing

int findmaxBitonic(int arr[], int size)
{
    int start = 0;
    int end = size-1;
    int mid;
    while(start <= end)
    {
        mid = start + (end-start)/2;
        if ((arr[mid] >= arr[mid-1]) && (arr[mid] >= arr[mid+1]))
        {
            return arr[mid];
        }
        else if ((arr[mid] > arr[mid+1]) && (arr[mid] < arr[mid-1]))
        {
            end = mid-1;

        }
        else
        {
            start = mid+1;
        }
    }

}

int main()
{
    int arr[] = {1,3,10,8,6,2}; // bitonic sequence
    int size = sizeof(arr)/sizeof(arr[0]);
    int max = findmaxBitonic(arr, size);
    printf("the maxima is %d\n",max);

}