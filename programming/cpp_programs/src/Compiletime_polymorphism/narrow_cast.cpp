#include <cstdio>
#include <stdexcept>

template <typename From, typename To>

To narrow_cast(From value)
{
    const auto converted = static_cast<To>(value);
    const auto backwards = static_cast<From>(converted);
    if (value != backwards)
    {
        throw std::runtime_error("Narrowing conversion!");
    }
    return converted;
}

int main()
{
    int perfect {496};
    const auto perfect_short = narrow_cast<int, short>(perfect);
    printf("perfect short = %d\n", perfect_short);
    try
    {
        int biggy {145679};
        const auto biggy_short = narrow_cast<int, short>(biggy);
        printf("biggy short = %d\n", biggy_short);
    }
    catch(const std::exception& e)
    {
        printf("exception caught : %s\n",e.what());
    }
    
}