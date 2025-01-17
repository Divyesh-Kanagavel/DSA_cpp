#include <cstdio>
 
/* using quick sort algorithm to find the kth index after sorting -> quick select*/

/*
Notes : 
1. Best time complexity : O(logn)
2. Average time complexity : O(logn)
3. Worst time complexity : (n^2)
4. Space complexity : O(logn) worst case : O(n) 
*/

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void quickSelectCore(int arr[], int low, int high, int index)
{
    if (low >= high)
        return;
    
    int pivot = arr[high];
    int i = low-1;
    for(int j=low; j < high;j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    pivot = i+1;
    if (index < pivot)
        quickSelectCore(arr, low, pivot-1,index);
    else if (index > pivot)
        quickSelectCore(arr, pivot+1, high, index);
    
    
}

int quickSelect(int arr[], int size, int index)
{
    quickSelectCore(arr, 0, size-1, index-1);
    return arr[index-1]; // array starts from index 0
}

int main()
{
    int arr[] = {4,10,13,10,7,1,19,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    int index = 6; // we would like to get 3rd element after sorting
    int element = quickSelect(arr, size, index);
    printf("%d\n", element);

    return 0;
}