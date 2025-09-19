// given a sequence, find three numbers whose sum is 0, if they exist...
#include <iostream>
#include <array>
#include <chrono>
#include <algorithm>
#include <unordered_map>

#define NUM 3
std::unordered_map<int, int> lut;

// brute force solution - O(N^3)
void tripleSum_bf(std::array<int, NUM>& arr)
{
    for(int i=0;i<NUM;i++)
    {
        for(int j=i+1;j<NUM;j++)
        {
            for(int k=j+1;j<NUM;k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    std::cout << "Solution found at " << arr[i] << ", " << arr[j] << ", " << arr[k] << std::endl;
                    return;
                }
            }

        }
    }
    std::cout << "no solution found!" << std::endl;
}

// O(N^2log(N))
void tripleSum_sort(std::array<int, NUM>& arr)
{
    std::sort(arr.begin(), arr.end());
    for(int i=0;i<NUM;i++)
    {
        for(int j=i+1;j<NUM;j++)
        {
            if (std::binary_search(arr.begin(), arr.end(), -(arr[i]+arr[j])))
            {
                std::cout << "Solution found at " << arr[i] << ", " << arr[j] << ", " << -(arr[i]+arr[j]) << std::endl;
                return;
            }
            
        }
    }
    std::cout << "no solution found!" << std::endl;

}

void tripleSum_lut(std::array<int, NUM>& arr)
{
    for(int i=0;i<NUM;i++)
    {
        for(int j=0;j<NUM;j++)
        {
            if (lut.find(-(arr[i]+arr[j]))!=lut.end())
            {
                std::cout << "solutio found at : " << arr[i]<< ", " << arr[j] << ", " << -(arr[i]+arr[j]) << std::endl;
                return;
            }
        }
    }

    std::cout << "No solution found!\n";

}

void two_pointer(std::array<int, NUM>& arr)
{
    std::sort(arr.begin(), arr.end());
    bool sol_found = 0;
    for(int i=0;i < NUM-2;i++)
    {
        int left = i+1;
        int right = NUM-1;
        while(left < right)
        {
            int total = arr[i] + arr[left] + arr[right];
            if (total == 0)
            {
                std::cout << "solution found at : " << arr[i] << ", " << arr[left] << ", " << arr[right] << std::endl;
                sol_found = true;
                left++;
                right--;
            }
            else if (total < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    if (!sol_found)
    {
        std::cout<< "no solution found!\n";
    }
}



int main()
{
    std::array<int,NUM> seq = {2,3,4}; // {-7,-4,-3,0,1,2,3,8,9}


    auto start = std::chrono::steady_clock::now();

    two_pointer(seq);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> duration = (end-start);
    std::cout << duration.count() << std::endl;
    return 0;
}