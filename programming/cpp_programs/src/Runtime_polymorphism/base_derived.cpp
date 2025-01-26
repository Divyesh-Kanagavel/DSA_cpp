#include <cstdio>

struct BaseClass {

};

struct DerivedClass : BaseClass
{};

void func(BaseClass &baseclass)
{}

void func2(DerivedClass& derivedclass)
{}

int main()
{
    DerivedClass derivedclass;
    BaseClass baseclass;
    func(derivedclass); // compiles - derived class object reference can be treated as base class reference
   // func2(baseclass); // does not compile - cannot pass base class reference in place of derived class reference
    // derived class is a base class, but base class is not a derived class.
    return 0;
}