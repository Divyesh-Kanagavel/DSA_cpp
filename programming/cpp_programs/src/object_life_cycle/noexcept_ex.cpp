#include <stdexcept>
#include <cstdio>

// if our function does not throw an exception it is use noexcept keyword
// this way compiler does not check for exceptions and thus the code is optimized.
// but if noexcept is used and exception is thrown, cpp will call std::terminate and program will abort
bool is_odd(int x) noexcept
{
    return (1==x%2);
}

int main()
{
    int x = 3;
    printf("%d\n", is_odd(x));
    return 0;
}
