#include <cstdio>

/*
Notes:
Time complexity : O(n^2) -> all three
Space complexity : O(1)
Stable : False
*/

void selectionSort(int arr[], int size)
{
    int max, temp,i,j;
    for(i=0;i<size;i++)
    {
        max = 0;
        for(j=0;j<size-i;j++)
        {
            if (arr[j] > arr[max])
            {
                max = j;
            }
        }
        temp = arr[size-i-1];
        arr[size-i-1] = arr[max];
        arr[max] = temp;
    }
}

int main()
{
    int arr[] = {4,10,13,10,7,1,19,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, size);
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}