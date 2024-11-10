// program to find duplicate element in an array
#include <cstdio>
#include <unordered_set>

int main(void)
{
    int arr[] = {1,2,3,4,5,1,2,3,4,5,6,6,6,0,2,4,7,9,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::unordered_set<int> set_arr;
    std::unordered_set<int> duplicates;

    for(int i=0;i<n;i++)
    {
        if (set_arr.find(arr[i])==set_arr.end())
        {
            set_arr.insert(arr[i]);
        }
        else
        {
            duplicates.insert(arr[i]);
        }
    }

    for(int i:duplicates)
    {
        printf("%d ",i);
    }
    printf("\n");


}