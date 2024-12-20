/* there are numbers in range 1-n, but one number is extra, find the extra number */
#include <cstdio>
int extraNumber(int arr[], int size)
{
    int xor_arr = 0;
    for(int i=0;i<size;i++)
    {
        xor_arr ^= arr[i];
    }
    for(int i=1;i<=size+1;i++)
    {
        xor_arr ^= i;
    }
    return xor_arr;
}

int main()
{
    int arr[] = {1,3,4,5,9,10,2,7,8,6,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int n = extraNumber(arr, size);
    printf("the extra number is %d\n", n);
}