/* check if two arrays are permutations of one another */
#include <cstdio>
#include <algorithm>
#include <unordered_map>

//method 1 : sort both the arrays and check if they are same
// time complexity : O(nlogn) , space complexity : O(1)
bool checkPermutation(int arr1[], int size1, int arr2[], int size2)
{
    if (size1 != size2)
        return false;
    std::sort(arr1, arr1+size1);
    std::sort(arr2,arr2 + size2);

    for(int i=0; i < size1; i++)
    {
        if (arr1[i]!=arr2[i])
            return false;
    }
    return true;
}

// method 2: use hashmap to store elements of one array and check the second array with this hashmap
bool checkPermutation2(int arr1[], int size1, int arr2[], int size2)
{
    if (size1!=size2)
        return false;
    std::unordered_map<int,int> hashmap;
    for(int i=0;i<size1;i++)
        hashmap[arr1[i]] = 1;

    for(int i=0;i<size2;i++)
    {
        if (hashmap.find(arr2[i]) == hashmap.end())
            return false;
    }

    return true;   
}

int main()
{
    int arr1[] = {1,4,5,6,9};
    int arr2[] = {9,1,5,4,6};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);

    if (checkPermutation2(arr1, size1, arr2, size2))
    {
        printf("arrays are permutations of one another\n");
    }
    else
    {
        printf("arrays are not permutations of one another\n");
    }

    
}