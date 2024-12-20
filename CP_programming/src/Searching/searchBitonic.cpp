/* search for an element in a bitonic array -> using modified binary search */
#include <cstdio>
#include <algorithm>

// we use a modified binary search to find the max first ~ O(logn)
// then once we have max, we search through both increasing sequence and decreasing sequence using binary search.

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
            return mid;
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

int binary_search(int arr[], int left, int right, int key, int isInc)
{
    int mid;
    if (left > right)
        return -1;
    mid = left + (right-left)/2;
    if (key == arr[mid])
        return mid;
    
    if ((isInc && (key < arr[mid])) || (!isInc && (key > arr[mid])))
        return binary_search(arr, left, mid-1, key, isInc);
    else
        return binary_search(arr, mid+1, right, key, isInc);
}


int searchBitonic(int arr[],int size,int key)
{
    int max_idx = findmaxBitonic(arr, size);
    int k = binary_search(arr, 0, max_idx,key, true);
    if (k!=-1)
        return k;
    else
        return binary_search(arr, max_idx+1, size-1, key, false);

}

int main()
{
    int arr[] = {1,3,10,8,6,2}; // bitonic sequence
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 11;
    int index = searchBitonic(arr, size, key);
    printf("the key %d is found at index %d\n", key, index);
}