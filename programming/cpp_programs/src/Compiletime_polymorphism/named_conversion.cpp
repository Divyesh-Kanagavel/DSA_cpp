// a file about named conversion functions - conceptually close to templates

#include <cstdio>
#include <stdexcept>

int main()
{
    float a = 2.3f;
    printf("[float] a = %f\n",a);
    int b = static_cast<int>(a); // named conversion to cast a to int at compile time
    printf("[int] b = %d\n",b);
    float *x = new float[3];
    x[0] = 2.5f;
    x[1] = 3.6f;
    x[2] = 4.7f;
    printf("before reinterpret cast [float] %f, %f, %f\n", x[0],x[1], x[2]);
    int *y = reinterpret_cast<int*>(x); // named conversion to interpret float buffer as int 
    printf("after reinterpret cast [int] %d, %d, %d\n", y[0],y[1], y[2]);
    const int c = 5;
    printf("[const int] c = %d\n",c);
    int& d = const_cast<int&>(c);
    d = 6;
    printf("after const cast modified value %d\n", d);
    return 0;

    
}