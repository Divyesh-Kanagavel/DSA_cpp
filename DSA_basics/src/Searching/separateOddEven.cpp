/* separate odd and even elements in an array */

#include <cstdio>

// method 1 : brute force approach : iterate through the array, if number is odd, put it in another array. 
// time complexity : O(n), space complexity : O(n)
void separateOddEven(int arr[], int size)
{
    int* arrSeparated = new int[size];
    int i;
    int start = 0;
    int end = size-1;
    for(i=0;i<size;i++)
    {
        if (arr[i]%2 == 0) // even{
        {
            arrSeparated[start++] = arr[i];
        }
        else
        {
            arrSeparated[end--] = arr[i];
        }
    }
    for(i=0;i<size;i++)
    {
        printf("%d ",arrSeparated[i]);
    }
    printf("\n");
    delete[] arrSeparated;

}

// method 2 : two pointer approach : time complexity : O(n), space complexity : O(1)
void separateOddEven2(int arr[], int size)
{
    int start = 0;
    int end = size-1;
    while(start <= end)
    {
        if (arr[start]%2 == 0)
        {
            start++;
        }
        else if (arr[end]%2 == 1)
        {
            end--;
        }
        else{
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    for(int i=0;i<size;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {12,34,45,9,8,90,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    separateOddEven2(arr, size);
}