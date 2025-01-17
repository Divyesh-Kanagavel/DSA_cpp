/* remove duplicates from an array */

#include <cstdio>
#include <algorithm>

// method : sort the array and then have two pointers -> one moves through the array, and the other one puts only those elements which are unique
// time complexity : O(nlogn) + O(n) = O(nlogn) , space complexity : O(1)
int removeDuplicates(int arr[], int size)
{
    if (size == 0)
        return 0;
    std::sort(arr, arr+size);
    int i;
    int j=0;
    for(i=1;i<size;i++)
    {
        if (arr[i] != arr[j])
        {
            j++;
            arr[j] = arr[i];
        }
    }
    return j+1;
}
 
int main()
{
    int arr[] = {1,5,6,9,2,3,1,0,7,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int index = removeDuplicates(arr, size);
    if (0!=index)
    {
        for(int i=0;i<index;i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else
    {
        printf("no element \n");
    }
}