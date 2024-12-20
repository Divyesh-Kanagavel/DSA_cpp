#include <cstdio>

int binarySearchRecursive(int arr[], int left, int right, int key)
{
    if (left > right)
    {
        return -1;
    }
    int mid = left + (right-left)/2;
    if (key == arr[mid])
    {
        return mid;
    }
    else if (key > arr[mid])
{
    return binarySearchRecursive(arr, mid+1, right, key);
}
else{
    return binarySearchRecursive(arr, left, mid-1, key);
}


}

int main()
{
    int arr[] = {1,4,5,6,7,11,21,23};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 2;
    int index = binarySearchRecursive(arr, 0, size-1, key);
    if(-1 != index)
    {
        printf("key %d found at index %d\n", key, index);
    }
    else
    {
        printf("key %d not found!\n", key);
    }
    return 0;
}