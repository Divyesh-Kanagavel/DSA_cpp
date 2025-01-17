/* transform array - [a1 a2 a3 a4 b1 b2 b3 b4] -> [a1 b1 a2 b2 a3 b3 a4 b4]*/
// start from the middle, swap the middle pair, then swap the middle two pairs , then swap middle three pairs and so on

#include<cstdio>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void transformArray(int arr[], int size)
{
    int mid = size/2;
    for(int i=1;i<mid;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(&arr[mid-i+2*j], &arr[mid-i+2*j+1]);
        }
    }
    printf("after transforamtion!\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {1,2,3,4,1,2,3,4}; 
    int size = sizeof(arr)/sizeof(arr[0]);
    transformArray(arr, size);

}