#include <iostream>
using namespace std;

int abs_value(int x)
{
    return x >= 0 ? x : x * -1;
}

int main()
{
    int my_num = 0;
    printf("%d\n", abs_value(my_num));
    return 0;
}