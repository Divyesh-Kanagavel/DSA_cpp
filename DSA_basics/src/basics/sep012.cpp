#include <cstdio>
// program to separate 0s 1s and 2s -> 000...111...222
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void sep_arr(int arr[], int n)
{
    int start = 0;
    int end = n-1;
    int num_swaps = 0;
    // first loop : push 2s to the right
    while(start < end)
    {
        if ((arr[start] == 2) && (arr[end]!=2))
        {
            swap(arr, start,end);
            num_swaps++;
            start++;
            end--;
        }
        else
        {
            if (arr[start]!=2)
            {
                start++;
            }
            if (arr[end] == 2)
            {
                num_swaps++;
                end--;
            }
        }
    }
    // second loop - to push 1s to right before 2
    start = 0;
    end = n-num_swaps-1; // end exludes all 2s pushed to right
    while(start < end)
    {
                if (arr[start] == 1 && arr[end] == 0)
        {
            swap(arr, start,end);

            start++;
            end--;

        }
        else
        {
            if (arr[start] == 0)
            {
                start++;
            }
            if (arr[end] == 1)
            {
                end--;
            }
        }
    }

}

int main(void)
{
    int arr[] = {0,0,1,2,0,2,1,0,0,2,1,1,2,1,2,0,1,0,0,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    sep_arr(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;

}