/* an array with 0s and 1s . partition the array with 0s first and 1s after 0s */
#include <cstdio>

// method 1 : two pointer algorithm -> push the 0s in the front and 1s in the back
// time complexity : O(n), space complexity : O(1) modifies array in place
void sep01(int arr[], int size)
{
    if (size<=1)
        return;
    int left = 0;
    int right = size-1;
    while(left < right)
    {
        if (arr[left] == 1 && arr[right] == 0)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
        if (arr[left] == 0)
            left++;
        if (arr[right] == 1)
            right--;
    }

}

// method 2 : quick select partition -> time complexity : O(n), space complexity : O(1)
void sep01_2(int arr[], int size)
{
    if (size<=1)
        return;
    
    int left = 0;
    for(int right = 1;right < size;right++)
    {
        if (arr[right] == 0)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
        }
    }
}

// method 3 : count the number of 0s and 1s and then fill the array with 0s first and 1s after 0s
// time complexity : O(n), space complexity : O(1)
void sep01_3(int arr[], int size)
{
    if (size<=1)
        return;
    int count0 = 0;
    for(int i=0;i<size;i++)
    {
        if (arr[i] == 0)
            count0++;
    }
    for(int i=0;i<count0;i++)
        arr[i] = 0;
    for(int i=count0;i<size;i++)
        arr[i] = 1;
}

int main()
{
    int arr[] = {1,0,1,0,0,1,1,1,0,0,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    sep01_3(arr, size);
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}