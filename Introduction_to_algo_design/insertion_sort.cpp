#include <iostream>
#include <algorithm>
using namespace std;

void insertion_sort(int arr[], int n)
{
    int i,j;
    for (i = 1; i < n; i++)
    {
        j = i;
        while((j > 0) && (arr[j] < arr[j-1]))
        {
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}
int main()
{
    const int N = 5;
    int arr[N] = {54,90,12,47,33};
    insertion_sort(arr, N);
    std::cout << "After sorting the array is : " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}