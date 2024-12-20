/* find the element which occurs maximum number of times in an array */
#include <cstdio>
#include <algorithm>
#include <unordered_map>

// method 1 : brute force search. Time complexity : O(n), space complexity : O(1)
int findMode(int arr[], int size)
{
    int i,j;
    int maxCount = 0;
    int count;
    int max = arr[0];
    for (i=0;i<size;i++)
    {
        count = 1;
        for(j=i+1;j<size;j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            max = arr[i];
        }
    }

    return max;

}

// method 2 : sort the elements and then find Mode. time complexity : O(nlogn), Space complexity : O(1)
int findMode2(int arr[], int size)
{
    int i;
    int maxCount = 0;
    int count = 1;
    int max = arr[0];
    std::sort(arr, arr+size); // sort the array : O(nlogn)
    for(i=1;i<size;i++)
    {
        if (arr[i] == arr[i-1])
        {
            count++;
        }
        else
        {
            count = 1;
        }
        if (count > maxCount)
        {
            maxCount = count;
            max = arr[i];
        }
    }
    return max;

}

// method 3 : using hash table - Time complexity : O(N), Space complexity : O(N)
int findMode3(int arr[], int size)
{
    int i;
    int maxCount = 0;
    int max = arr[0];
    std::unordered_map<int,int> hash_map;
    for(i=0;i<size;i++)
    {
        hash_map[arr[i]]++;
        if (hash_map[arr[i]] > maxCount)
        {
            maxCount = hash_map[arr[i]];
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int arr[] = {3,4,5,1,4,3,0,9,1,7,4};
    int size=  sizeof(arr)/sizeof(arr[0]);
    int max_el = findMode3(arr, size);
    printf("the element which occurs maximum number of times is %d\n", max_el);
    return 0;
}