// find kth largest element in array

#include <iostream>
#include <vector>

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

int quick_select(vector<int>& a, int k)
{
    int low = 0;
    int high = a.size()-1;

    while (high > low)
    {
        int j = partition(a, low, high);
        if (j < k) low = j+1;
        else if (j > k) high = j-1;
        else return a[k];
    }
    return a[k];
}

int main()
{
    vector<int> a = {4,0,1,6,8,3,2,1};
    cout << quick_select(a, 5) << endl;
    return 0;
}