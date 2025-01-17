/* find pair of elements in an array whose sum is equal to value*/

#include <cstdio>
#include <algorithm>
#include <unordered_map>

// method 1 : brute force. run two loops and find the pair such that we have a sum. 
// time complexity : O(n^2)
int findPair(int arr[], int size, int value)
{
    int i,j;
    for (i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if (arr[i]+arr[j] == value)
            {
                printf("Pair found : %d and %d\n", arr[i], arr[j]);
                return 1;
            }
        }
    }
    return 0;
}

// approach 2 : sort the array and then use two pointers [one at front and one at back] to find the pair
// time complexity : O(nlogn) + O(n) -> O(nlogn), space complexity : O(1)
int findPair2(int arr[], int size, int value)
{
    int i;
    std::sort(arr, arr+size);
    int front = 0;
    int back = size-1;
    while(front < back)
    {
        if (arr[front] + arr[back] == value)
        {
            printf("pair found : %d and %d\n", arr[front], arr[back]);
            return 1;
        }
        else if (arr[front] + arr[back] < value)
        {
            front++;
        }
        else
        {
            back--;
        }
    }
    return 0;
}

// approach 3 : use hash map to store elements in the array, if value - arr[i] exists, print the pair and exit
// time complexity : O(n) and space complexity : O(n)
int findPair3(int arr[], int size, int value)
{
    std::unordered_map<int, int> hash;
    for(int i=0;i<size;i++)
    {
        if (hash.find(value-arr[i])!=hash.end())
        {
            printf("pair found : %d and %d\n", arr[i], value-arr[i]);
            return 1;
        }
        hash[arr[i]] = 1;
    }
    return 0;
}

int main()
{
    int arr[] = {1,3,4,9,5,10,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int value = 3;

    int result = findPair3(arr, size, value);
    return 0;
}