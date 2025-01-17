/*Assumption : the array is sorted in increasing order*/

#include <cstdio>

int binarySearch(int arr[], int left, int right, int key)
{
    int mid;
    while(left <= right)
    {
        mid = left + (right-left)/2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid+1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1,4,7,11,16,17,21};
    int size  = sizeof(arr)/sizeof(arr[0]);
    int key = 22;
    int index = binarySearch(arr,0,size-1,key);
    if (-1 != index)
    {
        printf("key %d found at index %d\n", key, index);
    }
    else
    {
        printf("key %d not found!\n",key);
    }
    return 0;
}