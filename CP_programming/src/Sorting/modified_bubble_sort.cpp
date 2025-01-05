#include <cstdio>

/*
Notes : 
Worst case performance : O(n^2)
Average case performance : O(n^2),
Space complexity : O(1),
Due to modification : Best case performance : o(n),
Stable sort : True [Input order retained when identical elements present]
*/
void modifiedBubbleSort(int arr[], int size)
{
    if (size < 2)
        return;
    
    int temp;
    int swapped = 1;
    for(int i=0;i < (size-1) && swapped; i++)
    {
        swapped = 0;
        for(int j=0;j < (size-i-1); j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
    }
}

int main()
{
    int arr[] = {4,10,13,7,1,0,19};
    int size = sizeof(arr)/sizeof(arr[0]);
    modifiedBubbleSort(arr,size);
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}