/*
check if an array is a permutation of another array
*/

#include <array>
#include <algorithm>
#include <iostream>
using namespace std;

bool ispermutation(array<int, 5> a, array<int, 5> b)
{
    if (a.size() != b.size())
        return false;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    if (a == b)
        return true;
    return false;
}

int main()
{
    array<int, 5> a = {3,5,0,8,7};
    array<int, 5> b = {5,0,7,3,4};
    
    cout << ispermutation(a,b) << endl;
}