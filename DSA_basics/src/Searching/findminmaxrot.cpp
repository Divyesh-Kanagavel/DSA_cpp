/* find min and max of a rotated sorted array */
#include <cstdio>
#define ERROR -1000

int findMax(int arr[], int size)
{
    if (size == 0)
        return ERROR;
    if (size == 1)
        return arr[0];
    
    int start = 0;
    int end = size-1;
    int mid;
    while(start <= end)
    {
        mid = start + (end-start)/2;
        if (arr[mid] >= arr[mid-1] && arr[mid] >= arr[mid+1])
            return arr[mid];
        
        if (arr[mid] > arr[start] && arr[mid] > arr[end])
            start = mid+1;
        else
            end = mid-1;               
    }
    return ERROR;

}

int findMin(int arr[], int size)
{
    if (size == 0)
        return ERROR;
    if (size == 1)
        return arr[0];
    
    int start = 0;
    int end = size-1;
    int mid;
    while(start <= end)
    {
        mid = start + (end-start)/2;
        if (arr[mid] <= arr[mid-1] && arr[mid] <= arr[mid+1])
            return arr[mid];
        if (arr[mid] > arr[start] && arr[mid] > arr[end])
            start = mid+1;
        else
            end = mid-1;         
    }
    return ERROR;    
   
}

int main()
{
    int arr[] = {3,5,8,11,15,1,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int max = findMax(arr, size);
    int min = findMin(arr, size);
   
    if (max!=ERROR && min!=ERROR)
        printf("max is %d and min is %d\n", max,min);
    else
        printf("no min or max found\n");
}