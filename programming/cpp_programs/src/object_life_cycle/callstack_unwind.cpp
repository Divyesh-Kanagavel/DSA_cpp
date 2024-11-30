#include <cstdio>
#include <cstring>
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

struct SimpleStringOwner
{
    SimpleStringOwner(const char* x) : string {10}
    {
        if (!string.append_line(x))
        {
            throw std::runtime_error("Not enough memory!\n");
        }
        string.print("Constructed");
    }
    ~SimpleStringOwner()
    {
         string.print("About to destroy");
    }
    private:
        SimpleString string;
};

void fn_c()
{
    SimpleStringOwner c {"cccccccccc"};

}

void fn_b()
{
    SimpleStringOwner b{"b"};
    fn_c();
}

int main()
{
    try
    {
        SimpleStringOwner a {"a"}; // object a is allocated
        fn_b(); // fn_b allocates object b, which in turns calls fn_c. there is a difficulty allocating object c due to memory constraints.
        // this throws an exception which is caught in the catch block below. before that all the local variables with automatic duration in the stack are cleaned up calling their destructors.
        SimpleStringOwner d{"d"};
    }
    catch(const std::exception& e)
    {
        printf("Exception caught : %s\n",e.what());
    }

}