#include <cstdio>
#include <algorithm>

int main()
{
    int arr[] = {4,2,1,5,2,6,9,10,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int val = 16;
    //approach 1
    std::sort(arr,arr+n); // O(nlogn)
    int start = 0;
    int end = n-1; // 2 pointer 
    while(start < end)
    {
        if (arr[start] + arr[end] == val)
        {
            printf("%d + %d = %d\n", arr[start],arr[end],val);
            break;
        }
        else if (arr[start] + arr[end] < val)
        {
            start++;
        }
        else
        {
            end--;
        }
    }

    return 0;





}