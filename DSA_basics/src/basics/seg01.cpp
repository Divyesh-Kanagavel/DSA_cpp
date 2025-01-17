// program to seggregate 0s and 1s in an array
#include <cstdio>

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void seg_arr(int arr[],int n)
{
    int start = 0;
    int end = n-1;

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
int main()
{
    int arr[] = {0,1,0,1,0,0,1,1,0,0,1,0,1,1,1,0,0};
    int n = sizeof(arr) / sizeof(arr[0]);
    seg_arr(arr, n);
    for (int i : arr)
    {
        printf("%d ",i);
    }
    printf("\n");
    return 0;
}