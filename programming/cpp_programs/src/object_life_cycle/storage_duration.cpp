#include <cstdio>
#include <thread>

struct Tracer
{
    Tracer(const char* name) : name {name}
    {
        printf("%s constructed. \n ", name);
    }
    ~Tracer()
    {
        printf("%s destructed \n", name);
    }

    private:
        const char* name;

};

static Tracer t1{"static variable"};
thread_local Tracer t2 {"thread local variable "};

int main()
{
    (void) t2; // thread_local variables are lazily constructed, that is they are
    //  constructed only when they are instantiated in a thread ,main() being the thread here.
    printf("A\n");
    Tracer t3{"automatic variable"};
    printf("B\n");
    Tracer* t4 = new Tracer{"dynamic variable"};
    printf("C\n");
    delete t4;
    return 0;
}