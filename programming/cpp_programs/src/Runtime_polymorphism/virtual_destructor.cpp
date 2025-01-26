#include <cstdio>

// Example 1: illustration of why virtual destructor is needed

struct BaseClass
{};

struct DerivedClass : BaseClass
{
    DerivedClass()
    {
        printf("Derived class constructor invoked!\n");
    }
    ~DerivedClass()
    {
        printf("Derived class destructor invoked!\n");
    }
};

struct BaseClass1
{
    virtual ~BaseClass1() = default;
};

struct DerivedClass1 : BaseClass1
{
    DerivedClass1()
    {
        printf("Derived class constructor invoked!\n");
    }
    ~DerivedClass1()
    {
        printf("Derived class destructor invoked!\n");
    }
};

int main()
{
    // in the following case, the derived class destructor is not invoked, instead the default base class destructor is invoked, whcih could lead to potential memory leak
    BaseClass *baseclass {new DerivedClass()};
    delete baseclass;
    // solution is to use virtual Destructor
    BaseClass1 *baseclass1 {new DerivedClass1()};
    delete baseclass1;
    return 0;
}