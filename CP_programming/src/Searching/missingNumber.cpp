/* program to find missing number in an array of length n-1 of range 1-n with no duplicates */
#include <cstdio>
#include <algorithm>
#include <unordered_map>

// approach 1 : the brute force approach : loop through all numbers in range 1 to n and in another loop through the array, and find the element which is not found in first loop
// time complexity : O(n^2), space complexity : O(1)
int missingNumber(int arr[], int size)
{
    int i,j;
    int found = 0;
    for(i=1;i<=(size+1);i++)
    {
        found = 0;
        for(j=0;j<size;j++)
        {
            if (arr[j] == i)
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            return i;
        }
    }
}

// approach 2 : find the missing element after sorting the array - Time complexity : O(nlogn), space complexity  :O(1)
int missingNumber2(int arr[], int size)
{
    std::sort(arr, arr+size); // sort the array in nlogn time complexity
    for(int i=0;i<size-1;i++)
    {
        if (arr[i+1] != (arr[i]+1))
        {
            return arr[i]+1;
        }
    }
}

// approach 3 : hash table approach - time complexity : O(n), space complexity : O(n)
// create a hash table for all elements in the range 1-n, and check the empty hash element.
int missingNumber3(int arr[], int size)
{
    int i;
    std::unordered_map<int, int> hash;
    for(i=0;i<size;i++)
    {
        hash[arr[i]] = 1;
    }

    for(i=1;i<=(size+1);i++)
    {
        if (hash.find(i) == hash.end())
        {
            return i;
        }
    }

}

// approach 4 : parse through the array and add n+1 to arr[arr[index]], this way we add n+1 at all indices except for the number which is missing
// during the second traversal, read the numbers with modulo n+1, the index at which the result is zero is the missing number
int missingNumber4(int arr[], int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        arr[(arr[i])%(size+1) - 1] += (size+1);
    }
    bool flag = false;
    for(i=1;i<=size;i++)
    {
        if (arr[i-1] < (size+1))
        {
            flag = true;
            return i;
        }
    }
    if (flag == false)
    {
        return size+1;
    }
    
}

// approach 5 : subtract the sum of array from the sum of natural numbers from 1 to n, the difference is the missing number
// time complexity : O(n) and space complexity : O(1)
int missingNumber5(int arr[], int size)
{
    int sum_arr= 0;
    // find the sum of arr
    for(int i=0;i<size;i++)
    {
        sum_arr += arr[i];
    }

    int sum_n = (size+1) * (size+2) / 2;
    return (sum_n - sum_arr);

}

// approach 6 : XOR operation : XOR all elements in the array and then XOR all elements from 1 to n. the result is the missing number
// time complexity : O(n) and space complexity : O(1)
// important property which helps solve the problem : a^a = 0, a^0 = a.
int missingNumber6(int arr[], int size)
{
    int xor_arr = 0;
    for(int i=0;i<size;i++)
    {
        xor_arr ^= arr[i];
    }

    for(int i=1;i<=(size+1);i++)
    {
        xor_arr ^= i;
    }

    return xor_arr;
}

int main()
{
    int arr[] = {3,4,6,9,10,1,7,5,8}; // array of length 9 in the range 1-10 with one element missing
    int size = sizeof(arr)/sizeof(arr[0]);
    int missing = missingNumber4(arr, size);
    printf("the missing number is %d\n",missing);
    return 0;
}