#include <cstdio>
#include <stdexcept>

// by default compiler will have copy and copy assignment constructors and that is usually
// memberwise copy of objects in the class and invoke copy constructors of member objects if any.
// this can be dangerous in certain applications and in such cases, it is better to not have compiler's copy constructor i.e prohibit copy of object to anotehr object of same class.

struct Replicant
{
    Replicant(const Replicant& other) = default; // default copy constructor
    Replicant& operator=(const Replicant& other) = default; // default copy assignment operator
};

struct NoConstructor
{
    NoConstructor(const NoConstructor& other) = delete;
    NoConstructor& operator=(const NoConstructor& other) = delete; // copy and copy assignment constructors suppressed.
}