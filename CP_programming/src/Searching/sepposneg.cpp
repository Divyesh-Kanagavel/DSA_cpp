/* program to separate positive and negative numbers */

#include <cstdio>
#include <algorithm>

// method 1: use two pointers -> accumulate negative numbers in the front and positive numbers from the back of the array
// time complexity : O(n) , space complexity : O(1) -> array modified.
void separatePosNeg(int arr[], int size)
{
    // no need to separate
    if (size == 0 || size==1)
        return;
    int left = 0;
    int right = size-1;
    while(left < right)
    {
        if (arr[left] >= 0 && arr[right] < 0)
        {
            // swap the numbers
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
        if (arr[right] > 0)
            right--;
        if (arr[left] < 0)
            left++;
    }
}

// method 2 : sort the array -> this will separate the numbers by itself
// time complexity : O(nlogn) , space complexity : O(1)
void separatePosNeg2(int arr[], int size)
{
    if (size == 0 || size ==1)
        return;
    std::sort(arr,arr+size);
}

int main()
{
    int arr[] = {3,5,-6,-9,2,8,-4};
    int size = sizeof(arr)/sizeof(arr[0]);
    separatePosNeg2(arr, size);
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}