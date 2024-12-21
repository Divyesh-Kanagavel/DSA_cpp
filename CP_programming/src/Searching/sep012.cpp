/* program to separate 0s, 1s, 2s */
#include <cstdio>

// method 1 : first pass, separate 0s from 1 and 2 , second pass separate 1s and 2s
void sep012(int arr[], int size)
{
    if (size<=1)
        return;
    
    int left = 0;
    int right = size-1;
    while(left < right)
    {
        if (arr[left] != 0 && arr[right] == 0)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
        if (arr[left] == 0)
            left++;
        if (arr[right]!=0)
            right--;
    }

    int count0;
    for(count0=0;arr[count0]==0; count0++);


    left = count0;
    right = size-1;
    while(left < right)
    {
        if (arr[left]== 2 && arr[right]==1)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
        if (arr[left]==1)
            left++;
        if(arr[right]==2)
            right--;
    } 

}

// method 2 : count number of 0s, 1s and 2s and then fill them in order
// time complexity : O(n), space complexity : O(1)
void sep012_2(int arr[], int size)
{
    if (size<=1)
        return;
    int count0 = 0, count1 = 1;
    for(int i=0;i<size;i++)
    {
        if(arr[i] == 0)
           count0++;
        if (arr[i]==1)
            count1++;
    }

    for(int i=0;i<count0;i++)
        arr[i] = 0;
    for(int i=count0;i<count0+count1;i++)
        arr[i] = 1;
    for(int i=count0+count1;i<size;i++)
        arr[i] = 2;
    
}
// method 3 : sort the array - it will be arranged in the right order
// time complexity : O(nlogn), space compelexity : O(1)

// method 4 : three way partitioning : dutch national flag algorithm
// time complexity : O(n), space complexity : O(1) -> efficient than method 1

void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}
void sep012_3(int arr[], int size)
{
    if (size<=1)
       return;
    
    int low = 0;
    int mid = 0;
    int high = size-1;
    while(mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(&arr[low], &arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid]==1)
            mid++;
        else if (arr[mid]==2)
        {
            swap(&arr[mid], &arr[high]);
            high--;
        }
    }
}

int main()
{
    // assumption : only 0s,1s and 2s are there - additional condition required if not
    int arr[] = {1,1,2,0,1,2,0,0,1,1,2,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    sep012_3(arr, size);
    for(int i=0;i<size;i++)
       printf("%d ",arr[i]);
    printf("\n");
    return 0;
}