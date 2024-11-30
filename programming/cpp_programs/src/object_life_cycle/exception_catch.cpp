#include <cstdio>
#include <stdexcept>

struct Groucho
{
    void forget(int x)
    {
        if (x == 0xFACE)
        {
            throw std::runtime_error("exception thrown!\n");
        }
        printf("Groucho forgets %x\n",x);
    }
};
int main()
{
    Groucho groucho;
    try
    {
        groucho.forget(0xC0DE);
        groucho.forget(0xFACE);
        groucho.forget(0xABCD);
    }
    catch(const std::exception& e)
    {
        printf("exception caught with message %s\n", e.what());
    }
    return 0;
    
}