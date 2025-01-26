// an example of simple unique pointer class using templates
#include <cstdio>
#include <utility>
template <typename T>

struct Simple_uniqueptr
{
    Simple_uniqueptr() = default;
    Simple_uniqueptr(T* ptr) : ptr {ptr}
    {}
    ~Simple_uniqueptr()
    {
        if (ptr)
            delete ptr;
    }
    
    Simple_uniqueptr(const Simple_uniqueptr&) = delete; // we need a unique ptr -> so no double ownership of resources
    Simple_uniqueptr& operator=(const Simple_uniqueptr&) = delete;

    Simple_uniqueptr(Simple_uniqueptr&& other) noexcept : ptr {other.ptr}
    {
        other.ptr = nullptr;
    }
    Simple_uniqueptr& operator=(Simple_uniqueptr&& other) noexcept
    {
            if (ptr)
                delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
 
        return *this;
    }
    T* get_ptr() const
    {
        return ptr;
    }
    private :
        T* ptr;

};

// Tracer class to analyze the working of Simple_uniqueptr
struct Tracer {
    Tracer(const char* name) : name{ name } {
    printf("%s constructed.\n", name);
    }
    ~Tracer()
    {
        printf("%s destructed.\n",name);
    }
    private:
        const char* name;
};

void consumer(Simple_uniqueptr<Tracer> consumer_ptr)
{
    printf("(cons) Consumer got the pointer %p\n", consumer_ptr.get_ptr());
}

int main()
{
    auto ptr_a = Simple_uniqueptr<Tracer>(new Tracer{"ptr_a"});
    printf("(main) ptr_a points to %p\n", ptr_a.get_ptr());
    // when ptr_a is passed to consumer after std::move, the resources get transferred 
    // to consumer's argument. ptr_a is now in moved-from state.
    consumer(std::move(ptr_a));
    // when control returns from consumer, the ptr_a is destructed, because out of scope.
    
    printf("(main) ptr_a points to %p\n", ptr_a.get_ptr());
    return 0;
}