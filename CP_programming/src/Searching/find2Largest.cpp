/* find the second largest element in an unsorted array with minimum comparisons*/
// if there are two largest elements, the program returns one of them as second largest. 
// if this behavior is not desired, then modify the algorithm
#include <cstdio>
#include <algorithm>
#define ERROR -10000

// method 1 : find largest element , put it in end. then find the largest element again from 0 to n-2.
// number of comparisons : n-1+n-2 = 2n - 3
int find2ndLargest(int arr[], int size)
{
    if (size < 2)
        return ERROR;
    int largest = arr[0];
    int largestIndex = 0;
    for(int i=1;i<size;i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
            largestIndex = i;
        }
    }
    // push largest element to end
    int temp = arr[size-1];
    arr[size-1] = largest;
    arr[largestIndex] = temp;

    largest = arr[0];
    for(int i=1;i<size-1;i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}

// method 2 : sort the array and pick arr[size-2]. 
// time complexity : O(nlogn), space complexity : O(1)
int find2ndLargest2(int arr[], int size)
{
    if (size < 2)
        return ERROR;
    std::sort(arr, arr+size);
    return arr[size-2];
}

// method 3 : build a heap out of the array using buildHeap
// pick arr[1] or arr[2] depending on which one is smaller -> will be done in heap chapter.

int main()
{
    int arr[] = {3,1,5,10,10,6};
    int size= sizeof(arr)/sizeof(arr[0]);
    int secondLargest = find2ndLargest2(arr, size);
    if (ERROR!=secondLargest)
        printf("the second largest element is %d\n", secondLargest);
    else
        printf("no second largest element available\n");

    return 0;
}