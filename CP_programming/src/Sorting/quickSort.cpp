#include <cstdio>

/*Notes : 
Worst time complexity : O(n^2) 
Reason : when pivot is not chosen well, usually we have unbalanced partitions.
So, instead of log(n) recursive depth, we have recursive depth of n. 
And at each recursive depth we have n + n-1 + n-2 ... 1 comparison -> n^2
Average and best time complexity : O(nlogn) -> divide and conquer
Space complexity : O(1) for partition
                   O(logn) due to stack depth
                   O(n) in worst case [unbalanced partitions]
*/

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high)
{
     int i = low-1;
     int pivot = arr[high]; // pivot element
     for(int j=low;j<high;j++)
     {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);

        }
     }
     swap(arr[i+1],arr[high]);
     return i+1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low,pivot-1);
        quickSort(arr, pivot+1, high); // divide and conquer
    }
}

int main()
{
    int arr[] = {4,10,13,10,7,1,19,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0,size-1);
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
