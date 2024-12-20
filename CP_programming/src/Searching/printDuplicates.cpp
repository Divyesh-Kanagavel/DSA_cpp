/* print duplicate elements in an array - multiple approaches discussed */

#include <cstdio>
#include <algorithm>
#include <unordered_map> // for hashmap : method 3
#define NEGINF -999999

// method 1 : Exhaustive brute force approach - Time complexity : O(n^2), space complexity : O(1)
void printDuplicates(int arr[], int size)
{
    int i,j;
    printf("Repeating elements are : ");
    for(i=0;i<size;i++)
    {
        if (arr[i] == NEGINF)
        {
            continue;
        }
        for(j=i+1;j<size;j++)
        {
            if (arr[i] == arr[j])
            {
                printf("%d ",arr[i]);
                arr[j] = NEGINF;
            }
        }
    }
    printf("\n");
}

// method 2 : Using sorting - Time complexity : O(nlogn), Space complexity : O(1)
void printDuplicates2(int arr[], int size)
{
    std::sort(arr, arr+size); // sort the array - O(nlogn)
    printf("Repeating elements are : ");
    for(int i=1;i<size;i++)
    {
        if (arr[i] == arr[i-1])
        {
            printf("%d ",arr[i]);
        }
    }
    printf("\n");
}

// method 3 : using hash table - Time complexity : O(n), Space complexity : O(n)
void printDuplicates3(int arr[], int size)
{
    std::unordered_map<int, int> hashmap;
    int i;
    printf("Repeating elements are : ");
    for(i=0;i<size;i++)
    {
        if (hashmap.find(arr[i])==hashmap.end()) // O(1) complexity
        {
            hashmap[arr[i]]++;
        }
        else
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

}

// method 4 : counting - only works when the elements are in range of 0 to n-1 -> Time Complexity : O(n) and Space complexity : O(n)
void printDuplicates4(int arr[], int size)
{
    int *count = new int[size];
    for(int i=0;i<size;i++)
    {
        count[i] = 0;
    }
    int i;
    printf("repeating elements are : ");
    for(i=0;i<size;i++)
    {
        if (count[arr[i]] == 1)
        {
            printf("%d ",arr[i]);
        }
        else
        {
            count[arr[i]]++;
        }
    }
    printf("\n");


}
int main()
{
    int arr[] = {1,4,4,6,1,9,2,3,1,4,6,9,1,2,0,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    printDuplicates4(arr, size);
    return 0;
}