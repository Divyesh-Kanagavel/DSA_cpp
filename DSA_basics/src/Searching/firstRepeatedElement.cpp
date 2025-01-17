/* the objective is to find the first repeated element in an array */

#include <cstdio>
#define ERROR -10000
#include <unordered_map>

// method 1 : brute force -> check if the array is repeated in the second loop and if yes break
// time complexity : O(n^2), space complexity : O(1)
int firstRepeated(int arr[], int size)
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if (arr[i] == arr[j])
            {
                return arr[i];
            }
        }
    }
    return ERROR;
}

// method 2 : use a hash table to store number of times elements are repeated . In the second scan, if there is a repeat, return it
// time complexity : O(n), space complexity : O(n)
int firstRepeated2(int arr[], int size)
{
    std::unordered_map<int, int> hash;
    int i;
    for(i=0;i<size;i++)
    {
        hash[arr[i]]++;
    }
    for (i=0;i<size;i++)
    {
        if (hash[arr[i]] > 1)
            return arr[i];
    }
    return ERROR;
}

int main()
{
    int arr[] = {1,2,4,5,6,1,8,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    int num = firstRepeated2(arr,size);
    if (ERROR!=num)
        printf("the first repeated element is %d\n",num);
    else
        printf("no repeated element found\n");
    
    return 0;

}