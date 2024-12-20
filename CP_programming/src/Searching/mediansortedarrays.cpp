/* given two sorted arrays , find median of two sorted arrays after combining them 
that is merge two sorted array keeping it sorted  and get the number in median index */

#include <cstdio>

// method : merge the two sorted array element by element putting the smaller element first
// time complexity : O(n) , space complexity : O(1)
int findMedian(int arr1[], int arr2[], int size1, int size2)
{
    int medianIndex = ((size1 + size2) + (size1+size2)%2)/2; // this will be the median index based on sizes of arr1 and arr2
    int i=0;
    int j=0;
    int count = 0;
    while(count < medianIndex - 1)
    {
        if (i<size1 && (arr1[i] < arr2[j]))
        {
            i++;
        }
        else{
            j++;
        }
        count++;
    }
    if (arr1[i] < arr2[j])
        return arr1[i];
    else
        return arr2[j];
}

int main()
{
    int arr1[] = {1, 12, 15, 26, 38};
    int arr2[] = {2, 13, 17, 30, 45};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int median = findMedian(arr1, arr2, size1, size2);
    printf("the median of two sorted arrays is %d\n", median);
}