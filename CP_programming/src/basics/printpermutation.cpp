#include <cstdio>

void printArray(int* arr, int count)
{
    for(size_t i=0;i<count;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void permutation(int* arr, int i, int length)
{
    if (i == length)
    {
        printArray(arr, length);
    }

    int j;
    for (j=i; j < length;j++)
    {
        swap(arr, i, j);
        permutation(arr, i+1,length);
        swap(arr, i, j);
    }

}

int main(void)
{
    int arr[] = {0,1};
    permutation(arr, 0, 2);
    return 0;
}