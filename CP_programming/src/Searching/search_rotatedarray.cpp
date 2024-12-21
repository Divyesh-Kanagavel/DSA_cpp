/* the objective is to find an element in a rotated array -> using binary search*/

#include <cstdio>

// method : do binary search , since the array is rotated but sorted.
int searchRotatedArray(int arr[], int size, int target)
{
    int start = 0;
    int end = size-1;
    int mid;
    while(start <= end)
    {
        mid = start + (end-start)/2;
        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] > arr[start]) 
        {
            if (target < arr[mid] && target >= arr[start])
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        else
        {
            if (target > arr[mid] && target <= arr[end])
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
    }
    return -1;

}

int main()
{
    int arr[] = {4,5,6,7,8,1,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 11;
    int index = searchRotatedArray(arr, size,target);
    if (-1!=index)
    {
        printf("the target %d found at index %d\n",target, index);
    }
    else
        printf("the target is not found!\n");
}