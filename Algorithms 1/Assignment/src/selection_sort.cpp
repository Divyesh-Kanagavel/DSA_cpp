/* selection sort in C++ for generic datatype
Error handling not taken care of for simplicity */

#include <iostream>
#include <functional>

template <typename T>
bool lesser(T a, T b)
{
    return a < b;
}

template <typename T>
void exchange(std::vector<T>& vec, int a, int b)
{
    T temp = vec[a];
    vec[a] = vec[b];
    vec[b] = temp;
}
// pass the datatype of the vector as template and also the comparator function
template <typename T, typename Compare>
void selection_sort(std::vector<T>& vec, Compare comp)
{
    for(int i=0;i<vec.size();i++)
    {
        int min = i;
        for (int j=i+1;j<vec.size();j++)
        {
            if (comp(vec[j], vec[min]))
            {
                min = j;
            }
        }
        exchange(vec, i, min);
    }   
}

int main()
{
    std::vector<int> a = {4,2,4,9,10,1};
    // deduce the type of a and also the comparator function from here.
    selection_sort(a, lesser<int>);
    for(auto i : a)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

}
