// program to find maximum element in a sorted and rotated array
// e.g arr = {4,5,6,7,0,1,2} => max = 7.
#include <cstdio>

int find_max(int arr[], int n)
{
    int start = 0;
    int end = n-1;
    int max = arr[end];
    while(start < end)
    {
        int mid = start + (end-start)/2;
        if (arr[mid] > max)
        {
            max = arr[mid];
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
    }
    return max;

}

int main(void)
{
    int arr[] = {8,9,0,1,2,3,4,5,6,7};
    int n = find_max(arr,9);
    printf("%d\n",n);
}

