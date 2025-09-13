// find the max of a bitonic sequence

#include <iostream>
#include <array>
#include <algorithm>
#define NUM 10

int find_max_bitonic(std::array<int, NUM>& arr)
{
    int low = 0;
    int high = NUM - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Check boundaries safely
        if (mid > 0 && mid < NUM - 1)
        {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid; // found maximum

            // If middle is greater than left, we are on increasing slope
            if (arr[mid] > arr[mid - 1])
                low = mid + 1;
            else
                high = mid - 1;
        }
        else if (mid == 0) // only compare with right
        {
            if (arr[0] > arr[1])
                return 0;
            else
                return 1;
        }
        else if (mid == NUM - 1) // only compare with left
        {
            if (arr[NUM - 1] > arr[NUM - 2])
                return NUM - 1;
            else
                return NUM - 2;
        }
    }

    return -1; // should not reach if array is bitonic
}

int bin_search_inc(std::array<int, NUM>& arr, int low, int high, int key)
{
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return -1;
}

int bin_search_dec(std::array<int, NUM>& arr, int low, int high, int key)
{
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

 
int main()
{
    std::array<int,NUM> seq = {3,5,8,10,12,14,7,6,4,2} ; // bitonic sequence
    int key = 2;
    int idx = find_max_bitonic(seq);
    std::cout << idx << std::endl;
    int idx1 = bin_search_inc(seq, 0, idx, key);
    std::cout << idx1 << std::endl;
    if (idx1 == -1)
    {
        int idx2 = bin_search_dec(seq, idx+1, NUM-1, key);
        if (idx2 == -1)
        {
            std::cout << "not found!\n";
        }
        else
        {
            std::cout << "found at " << idx2 << std::endl;
        }

    }
    else
    {
        std::cout << "found at " << idx1 << std::endl;
    }
}