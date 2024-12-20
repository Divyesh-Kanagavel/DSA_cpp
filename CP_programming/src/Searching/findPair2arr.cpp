/* find a pair of numbers from two different arrays such that x + y = value */
#include <cstdio>
#include <algorithm>
#include <unordered_map>

// method 1: brute force -> two loops one for each array and check for sum == value
// time complexity : O(n^2), space complexity : O(1)
int findPair2arr(int arr1[], int arr2[], int size1, int size2, int value)
{
    int i,j;
    for(i=0;i<size1;i++)
    {
        for(j=0;j<size2;j++)
        {
            if(arr1[i] + arr2[j] == value)
            {
                printf("pair found : %d and %d\n", arr1[i], arr2[j]);
                return 1;
            }
        }
    }
    return 0;
}

// method 2 : sort one array, iterate through one array and find value-arr[i] in the other array using binary search
// time complexity ; O(mlogm) or O(nlogm), depending on n>m or m>n, space complexity : O(1)

int findPair2arr2(int arr1[], int arr2[], int size1, int size2, int value)
{
    // sort the second array
    std::sort(arr2, arr2+size2);
    for(int i=0;i<size1;i++)
    {
        int addend2 = value - arr1[i];
        if (std::binary_search(arr2, arr2+size2, addend2))
        {
            printf("pair found  : %d and %d\n", arr1[i], addend2);
            return 1;
        }
    }

    return 0;
}

// method 3 : use hash table to store elements of one array and the check if value - arr1[i] is present in hash table
// time complexity : O(n), space complexity : O(n)
int findPair2arr3(int arr1[], int arr2[], int size1, int size2, int value)
{
    std::unordered_map<int, int> hash;
    for(int i=0;i<size2;i++)
    {
        hash[arr2[i]] = 1;
    }

    for(int i=0;i<size1;i++)
    {
        if (hash.find(value - arr1[i])!=hash.end())
        {
            printf("pair found : %d and %d\n", arr1[i], value-arr1[i]);
            return 1;
        }
    }
    return 0;
}

int main()
{
    int arr1[] = {1,2,4,5,7};
    int arr2[] = {9,0,3,1,4};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    int value = 10;
    int result = findPair2arr3(arr1, arr2, size1, size2, value);
    return 0;
}