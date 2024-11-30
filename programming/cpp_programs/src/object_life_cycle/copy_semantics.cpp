// for POD, the copy is always member-wise. So, for fully featured class,
// the compiler assigns this default behaviour of member-wise copy and this 
// could be dangerous in some instances.
// to prevent use after free and double free bugs, it is better to take control of copy semantics and write your own 
// way of copy especially when dynamic memory allocation is done.
// default copy assignment operator for simpler data types is member wise copy from rhs object to lhs object.
// this is dangerous for two reasons - the buffer in lhs object might have data already and is rewritten without clearing the buffer.
// second reason is that the two objects point to same buffer pointer with potential danglign pointer problem or double frees.
// this has to be done cleaning the buffers and doing a deep copy.

#include <cstring>
#include <cstdio>
#include <stdexcept>

struct SimpleString
{
    SimpleString(std::size_t maxSize) : max_size {maxSize},length {}
    {
        if (max_size == 0)
        {
            throw std::runtime_error("max_size should be atleast 1!\n");
        }
        buffer = new char[max_size];
        buffer[0] = 0;
    }

    SimpleString(const SimpleString& other) : max_size {other.max_size},
    length {other.length}, buffer {new char[other.max_size]} // copy constructor - custom
    {
        std::strncpy(buffer,other.buffer,max_size);
    }

    SimpleString& operator=(const SimpleString& other)
    {
        if (this == &other)
        {
            return *this;
        }
        const auto new_buffer = new char[other.max_size];
        delete[] buffer;
        buffer = new_buffer;
        length = other.length;
        max_size = other.max_size;
        std::strncpy(buffer,  other.buffer,max_size);
        return *this;

    }
    ~SimpleString()
    {
        delete[] buffer;
    }

    void print(const char* tag) const
    {
        printf("%s: %s\n", tag, buffer);
    }

    bool append_line(const char* x)
    {
        const auto x_len = strlen(x);
        if ((x_len + length + 2) > max_size) 
        {
            return false;
        }
        std::strncpy(buffer + length, x, x_len);
        length += x_len;
        buffer[length++] = '\n';
        buffer[length] = 0;
        return true;

    }
    private:
        std::size_t max_size;
        std::size_t length;
        char* buffer;

};

int main()
{
/*
    SimpleString s1(100); // parametrized constructor
    s1.append_line("parametrized constructor called");
    SimpleString s2 {s1}; // copy constructor
    s1.append_line("again parametrized");
    s2.append_line("this time copy constructor");
    s1.print("s1");
    s2.print("s2");
*/
    SimpleString s1 {50};
    s1.append_line("Hi s1!");
    SimpleString s2{50};
    s2.append_line("Hi s2!");
    s1.print("s1");
    s2.print("s2");
    s2 = s1;
    s1.print("s1");
    s2.print("s2");
    return 0;
}
