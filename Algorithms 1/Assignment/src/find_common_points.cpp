/*
find number of common 2d points in a array with 2d points
*/

#include <algorithm>
#include <array>
#include <iostream>
#include <utility>

using namespace std;
using int_pair = pair<int, int>;

bool comp(const int_pair i, const int_pair j)
{
    if (i.first == j.first)
        return i.second < j.second;
    return i.first < j.first;
}

int num_common_points(array<int_pair, 6>& a, array<int_pair, 5>& b)
{
    std::sort(a.begin(), a.end(), comp);
    std::sort(b.begin(), b.end(), comp);

    int common_pts = 0;
    size_t left_ptr = 0;
    size_t right_ptr = 0;

    while(left_ptr!=a.size() && right_ptr!=b.size())
    {
        if (a[left_ptr] == b[right_ptr])
        {
            ++left_ptr;
            ++right_ptr;
            ++common_pts;
        }
        else if (comp(a[left_ptr], b[right_ptr]))
            ++left_ptr;
        else
            ++right_ptr;
    }

    return common_pts;

}

int main()
{
    array<int_pair, 6> a = {int_pair(3,4),int_pair(3,9), int_pair(9,4),int_pair(9,1), int_pair(8,7), int_pair(5,0)};
    array<int_pair, 5> b = {int_pair(3,9), int_pair(9,4), int_pair(1,4) ,int_pair(5,0), int_pair(6,3)};

    std::cout << num_common_points(a,b) << std::endl;






}