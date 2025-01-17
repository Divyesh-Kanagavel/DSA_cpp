/* given an array of 0s and 1s, with 0s before 1, find the first index of 1 */
#include <cstdio>

// method : the idea is to use binary search to narrow down to the first index of 1.
// the condition is to find the 1 which has 0 before it.
// time complexity : O(logn), space complexity : O(1)
int find1stindex(int arr[], int size)
{
    int start = 0;
    int end = size-1;
    int mid;
    while(start <= end)
    {
        mid = start + (end - start)/2;
        if (arr[mid] == 1 && (mid == 0 || arr[mid-1] == 0))
            return mid;
        else if (arr[mid] == 1)
            end = mid - 1;
        else
            start = mid+1;
    }
    return -1;
}

int main()
{
    int arr[] = {0,1};
    int size  =sizeof(arr)/sizeof(arr[0]);
    int index1 = find1stindex(arr, size);
    if (index1 != -1)
        printf("the first index of 1 is : %d\n", index1);
    else
        printf("no 1s found!\n");
}