/* find three elements in an array which sum to value*/

#include <cstdio>
#include <algorithm>

// method 1 : brute force -> time complexity : O(n^3), space complexity
void sumThree(int arr[], int size, int value)
{
    if (size < 3)
    {
        printf("not enough elements!\n");
        return;
    }
    int i,j,k;
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            for(k=j+1;k<size;k++)
            {
                if (arr[i]+arr[j]+arr[k] == value)
                {
                    printf("the value %d is sum of %d,%d,%d\n", value, arr[i],arr[j],arr[k]);
                    return;
                }
            }
        }
    }
    printf("no triplet found\n");
}

// method 2 : use sorting + brute force -> time complexity : O(nlogn) + O(n^2) = O(n^2), space complexity : O(1)

void sumThree2(int arr[], int size, int value)
{
    if (size < 3)
    {
        printf("not enough elements!\n");
        return;
    }
   
    std::sort(arr, arr+size);
    int i,j;
    int k = size-1; // pointer at last position
    bool tripletFound = false;
    for(i=0;i<size-2;i++)
    {
        int left = i+1;
        int right = size-1;
        while(left < right)
        {
            // duplicates allowed -> if not allowed, we could add condition to skip duplicates
            long long sum = static_cast<long long>(arr[i]) + static_cast<long long>(arr[left]) + static_cast<long long>(arr[right]);
            if (sum == value)
            {
                printf("triplet found : %d, %d, %d\n", arr[i],arr[left],arr[right]);
                tripletFound = true;
                left++;
                right--;
            }
            else if (sum < value)
            {
                left++;
            }
            else{
                right--;
            }
        }

    }
    if (!tripletFound)
        printf("no triplet found\n");


}

int main()
{
    int arr[] = {3,4,6,0,9,2,11,4,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int value = 15;
    sumThree2(arr,size,value);
    
    return 0;
}