/* count the occurences of an element in a sorted array*/

#include <cstdio>


// method 1 : brute force : iterate through the array and update count
// time complexity : O(n), space complexity : O(1)

int findKeyCount(int arr[], int size, int key)
{
    int count = 0;
    for(int i=0;i<size;i++)
    {
        if(arr[i] == key)
            count++;

    }
    return count;
}

int getFirstIndex(int arr[], int left, int right, int key)
{
    if (left > right)
        return -1;
    int mid = left + (right - left)/2;
    if (key == arr[mid] && (mid == left || arr[mid - 1] != key))
        return mid;
    if (key <= arr[mid])
        return getFirstIndex(arr, left, mid-1, key);
    else
        return getFirstIndex(arr, mid+1, right, key);
}

int getLastIndex(int arr[], int left, int right, int key)
{
    if (left > right)
        return -1;
    
    int mid = left + (right - left)/2;
    if (key == arr[mid] && (mid == right || arr[mid + 1] != key)) 
       return mid;
   
if (key < arr[mid])// <
{
return getLastIndex(arr, left, mid - 1, key); }
else
{
return getLastIndex(arr, mid + 1, right, key); }
}

// method 2 : binary search : since the array is sorted, we can think of some way to use binary search
// find the first occurence of the key and last occurence of key and subtract the indices to get the num occurences.
int findKeyCount2(int arr[], int size, int key)
{
    int firstIndex = getFirstIndex(arr, 0, size-1, key);
    printf("%d\n", firstIndex);
    int lastIndex = getLastIndex(arr, 0,size-1, key);
    printf("%d\n", lastIndex);
    return (lastIndex - firstIndex + 1);
}

int main(void)
{
    int arr[] = {1,2,2,2,3,3,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 3;
    int num_occurences = findKeyCount2(arr, size, key);
    if (-1!=num_occurences)
        printf("the key %d occurs %d times.\n", key, num_occurences);
    else
        printf("the key %d does not exist in the array.\n", key);
    return 0;
}