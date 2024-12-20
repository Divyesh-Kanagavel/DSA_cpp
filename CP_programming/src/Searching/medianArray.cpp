/* given an array, find the median of the array*/
#include <cstdio>
#include <algorithm>

// method 1 : sort the array and then return the middle element
// time complexity : O(nlogn) for sorting, space complexity : O(1)
int findMedian(int arr[], int size)
{
    std::sort(arr, arr+size); // sort the array
    return arr[size/2]; // return the median
}

// method 2: use quick select algorithm to find the median -> discussed in next chapter
// time complexity : O(1), space complexity : O(1)
int main()
{
    int arr[] = {1,5,7,9,2,0,4,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    int median = findMedian(arr, size);
    printf("median of array is %d\n",median);
}