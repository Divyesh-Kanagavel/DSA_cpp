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
    groucho.forget(0xFACE);
    return 0;
}