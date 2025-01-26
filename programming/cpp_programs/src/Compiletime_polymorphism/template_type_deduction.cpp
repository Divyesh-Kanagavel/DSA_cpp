#include <cstdio>

template <typename T>

T mean(const T* data, const size_t length)
{
    T sum {};
    for (size_t i{}; i < length; ++i)
    {
        sum += data[i];
    }
    if (length!=0)
        return (sum / length);
    else
        return 0;
}

int main()
{
    const int data_i[] {1,2,3,4,5};
    const auto result_i = mean(data_i, 5); // template type deduction in play -> mean<int> is the syntax, but the compiler can deduce the type from data_i
    printf("mean of data_i = %d\n",result_i);
    const double data_d[] {1.0,2.0,3.3,4.5,5.0};
    const auto result_d = mean(data_d, 5);
    printf("mean of data_d = %f\n",result_d);
    return 0;
}