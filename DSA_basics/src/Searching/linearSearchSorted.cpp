#include <cstdio>

int linearSearchSorted(int arr[], int size, int value)
{
    int i=0;
    for(i=0;i<size;i++)
    {
        if (value == arr[i])
        {
            return i;
        }
        if (value < arr[i]) // assumption : array is sorted in increasing order
        {
            return -1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1,4,5,6,7,10,11,15,16,19};
    int size = sizeof(arr)/sizeof(arr[0]);
    int index = linearSearchSorted(arr, size, 10);
    if (-1!=index)
    {
        printf("Element found at index : %d\n", index);
    }
    else
    {
        printf("Element not found\n");
    }
    return 0;
}