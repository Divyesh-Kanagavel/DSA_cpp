/* find the kth smallest element in the union of two sorted arrays */
#include <cstdio>
#define ERROR -100000

int min(int a, int b)
{
    return a < b ? a : b;
}
// method : since two arrays are sorted, we use something similar to binary search to search for kth smallest element
// 
int findkth(int arr1[], int arr2[], int size1, int size2, int k)
{
     if ((size1 + size2) < k)
        return ERROR;
    if (size1 == 0)
        return arr2[k-1];
    if (size2 == 0)
        return arr1[k-1];
    
    if (k == 1) // if first element is required, easier to return
        return min(arr1[0], arr2[0]);
    
    int i = min(size1, k/2);
    int j = min(size2, k/2); // Divide and conquers -> divide array into two parts and search for kth

    if (arr1[i-1] < arr2[j-1]) // if first arr has elements less than arr2, move to the right of arr1 to further check greater elements with arr2
        return findkth(arr1+i, arr2, size1-i, size2, k-i);
    else
        return findkth(arr1, arr2+j, size1, size2-j, k-j);
}

int main()
{
    int arr1[] = {1,3,4,5,6,9};
    int arr2[] = {2,7,10,14,15};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);

    int k = 4;

    int kth = findkth(arr1, arr2, size1, size2, k);
    if (kth!=ERROR)
        printf("the kth smallest element in union of sorted arrays : %d\n", kth);
    else
        printf("Arrays do not have k elements in total!\n");
    return 0;
}