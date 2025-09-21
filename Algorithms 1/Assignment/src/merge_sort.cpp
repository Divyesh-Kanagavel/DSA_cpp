/*
merge sort implementation
*/

#include <vector>
#include <iostream>
using namespace std;

void merge_array(vector<int>& a, vector<int>& aux_array, int low, int mid, int high)
{
    int left_ptr = low;
    int right_ptr = mid+1;
    int aux_ptr = low;
    while(left_ptr <= mid && right_ptr <= high)
    {
        if (a[left_ptr] <= a[right_ptr])
        {
            aux_array[aux_ptr++] = a[left_ptr++];
        }
        else
        {
            aux_array[aux_ptr++] = a[right_ptr++];
        }
    }
    while(left_ptr <= mid)
    {
        aux_array[aux_ptr++] = a[left_ptr++];
    }
    while(right_ptr <= high)
    {
        aux_array[aux_ptr++] = a[right_ptr++];
    }

    for(int i=low;i<=high;++i)
    {
        a[i] = aux_array[i];
    }
}

void merge_sort(vector<int>& a, int low, int high, vector<int>& aux_array)
{
    if (high <= low)
        return;
    int mid = low + (high-low) / 2;
    merge_sort(a , low, mid, aux_array);
    merge_sort(a, mid+1, high, aux_array);
    merge_array(a, aux_array, low, mid, high);
}

int main()
{
    vector<int> a = {4,1,0,9,8,1,7};
    vector<int> aux_array;
    aux_array.resize(a.size());
    merge_sort(a, 0 ,a.size()-1, aux_array);
    for(auto i:aux_array)
        std::cout << i << " ";
    std::cout << "\n";

}