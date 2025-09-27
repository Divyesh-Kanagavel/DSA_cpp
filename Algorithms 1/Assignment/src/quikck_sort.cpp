#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

void exchange(vector<int>& a, int i, int j)
{
    std::swap(a[i], a[j]);
}

int partition(std::vector<int>& a, int low, int high)
{
    int i = low;
    int j = high+1;

    while(true)
    {
        while(a[++i] < a[low])
         if (i == high) break;
        while (a[--j] > a[low])
            if (j == low) break;
        
        if (i >= j) break;
        exchange(a, i, j);
    }
    exchange(a, low, j);
    return j;
}

void quickSort(vector<int>& a, int low, int high)
{
    if (high <= low)
    {
        return;
    }
    int j = partition(a, low, high);
    quickSort(a, low, j-1);
    quickSort(a, j+1, high);
}

void quick_sort(vector<int>& a)
{
    random_device rd;
    mt19937 generator(rd());
    shuffle(a.begin(), a.end(), generator); // shuffling for performance guarantee of quick sort
    quickSort(a, 0, a.size()-1);
}

int main()
{
    vector<int> a = {4,0,8,4,5,7,11,41,3};
    quick_sort(a);
    for(auto i : a)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}