#include <cstdio>

int linearSearchUnsorted(int arr[], int size, int value)
{
    int i=0;
    for(i=0;i<size;i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[6] = {1, 9, 11, 12, 15, 17};
    int size = sizeof(arr)/sizeof(arr[0]);
    int index = linearSearchUnsorted(arr, size, 12);
    if (index!=1)
    {
        printf("element found at index %d\n",index);
    }
    else
    {
        printf("element not found\n");
    }
    return 0;
}