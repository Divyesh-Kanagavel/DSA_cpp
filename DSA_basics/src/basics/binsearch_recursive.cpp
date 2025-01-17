#include <cstdio>

int binsearch(int arr[],int left, int right, int key)
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
    binsearch(arr, left, mid-1, key);
    binsearch(arr, mid+1, right, key);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    int key = 5;
    int index = binsearch(arr, 0, n-1, key);
    printf("%d\n", index);
    return 0;
}