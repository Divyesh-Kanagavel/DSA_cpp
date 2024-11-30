#include <stdexcept>
#include <cstdio>
struct CyberDyneSeries800
{
    CyberDyneSeries800()
    {
        printf("Hi!\n");
    }
    ~CyberDyneSeries800()
    {
        throw std::runtime_error("exception in destructor!\n");
    }
};
int main()
{
    try
    {
        CyberDyneSeries800 cl;
        throw std::runtime_error("runtime error triggered in main!\n");
    }
    catch(const std::exception& e)
    {
        printf("Caught exception %s\n", e.what()); // ideally the exception thrown in try block is caught here and this is printed.
        // but while handling exception, the automatic object in try block is destructed and since there is an exception in destructor, compiler calls std::terminate.
    }
    return 0;
    
    
}