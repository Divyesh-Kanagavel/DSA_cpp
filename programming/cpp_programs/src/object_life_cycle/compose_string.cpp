#include <stdexcept>
#include <cstring>
#include <cstdio>

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

int main()
{
    SimpleStringOwner x{"x"};
    printf("x is alive\n");
    return 0;

}