#include <cstdio>
// program to find all maxima in an array

void find_maxima(int arr[],int n)
{
    if (arr[0] > arr[1])
    {
        printf("%d ", arr[0]);
    }
    for (int i=1;i<n-1;i++)
    {
        if (arr[i] > arr[i-1] && arr[i] > arr[i+1])
        {
            printf("%d ",arr[i]);
        }
    }
    if (arr[n-1] > arr[n-2])
    {
        printf("%d ", arr[n-1]);
    }

    printf("\n");

}
int main()
{
    int arr[] = {1,5,3,4,6,7,9,6,3,2,10,11,12,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    find_maxima(arr, n);
    return 0;
}