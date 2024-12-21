/*Given an array whose elements is monotonically increasing with both negative and positive numbers. Write an algorithm to find the point at which list becomes positive.*/

#include <cstdio>

// since the array is monotonically increasing, we use binary search
int findPos(int arr[], int size)
{
    if (size == 0)
        return -1;
    if (size == 1)
    {
        if (arr[0] > 0)
            return 0;
        else
            return -1;
    }
    int start = 0;
    int end = size-1;
    int mid;
    while(start<=end)
    {
        mid = start + (end-start)/2;
        if (arr[mid] > 0 && (mid==0||arr[mid-1]<=0))
            return mid;
        
        if(arr[mid] > 0)
        {
            end = mid-1;
        }
        else 
        {
            start = mid+1;
        }
    }
    return -1;

}

int main()
{
    int arr[] = {-4,-3,-1,0,5,6,9,11};
    int size = sizeof(arr)/sizeof(arr[0]);
    int index = findPos(arr, size);
    if (index == -1)
    {
        printf("no positive element\n");
    }
    else
    {
        printf("positive element found at index %d\n", index);
    }
}