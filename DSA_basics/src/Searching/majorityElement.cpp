/* find the majority element in an array. Majority element means : element which exists more than n/2 times. */

#include <cstdio>

// method 1 : brute force method - time complexity : O(n^2), Space complexity : O(1)
int findMajorityElement(int arr[], int size)
{
    int count=1;
    int i,j;
    int maxCount=0;
    int max = arr[0];
    for(i=0;i<size;i++)
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
    if (maxCount > size/2)
    {
        return max;
    }
    else
    {
        return 0;
    }
}

// method 2 : sort and then find the element. Time complexity : O(nlogn), space complexity : O(1)
/* intuition : if there is a majority element, the middle element has to be the element -> no other way
scan through the array after sorting and check if the count of middle element is greater than size/2*/
int findMajorityElement2(int arr[], int size)
{
    int majElement = arr[size/2]; // middle element
    int count = 0;
    for(int i=0;i<size;i++)
    {
        if (arr[i] == majElement)
            count++;
    }
    if (count > size/2)
    {
        return majElement;
    }
    else
    {
        return 0;
    }
}

// method 3 : cancellation approach : moore's voting algorithm.
// if a number has to be a majority element, it's number has to be greater than all the other elements combined.
// in the first traversal we pick the potential candidate by checking if its count is positive inspite of cancellation from other candidates
// in the second traversal, we count the number of the majority index candidate. hence time complexity : O(n), space complexity : O(1)

int findMajorityElement3(int arr[], int size)
{
    int majIndex = 0;
    int count = 1;
    int i;
    for(i=1;i<size;i++)
    {
        if (arr[majIndex] == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        
        if (count == 0)
        {
            majIndex = i;
            count = 1;
        }
    }

    count = 0;
    int candidate = arr[majIndex];
    for(i=0;i<size;i++)
    {
        if (arr[i] == candidate)
        {
            count++;
        }
    }
    if (count > size/2)
    {
        return candidate;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int arr[] = {1,1,1,1,2,3,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int element = findMajorityElement2(arr, size);
    if (0!=element)
    printf("the number %d is a majority element in the array\n",element);
    else
    {
        printf("no majority element!\n");
    }
}