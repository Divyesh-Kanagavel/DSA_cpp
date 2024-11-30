#include <cstdio>
#include <stdexcept>
#include <cstring>

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

int main()
{
    SimpleString string {115};
    string.append_line("Hi Divyesh!");
    string.append_line("Hi there!");
    string.print("A");
    string.append_line("Hi Harsha!");
    string.append_line("Hi all");
    string.print("B");
    string.append_line("Coming home from war is very memorable.you get to tell wartime stories!");
    string.print("C");
    if (!string.append_line("but going to war could be emotional.but when duty calls, you got to go!"));
    {
        printf("string is too large to accommodate in buffer!\n");
    }

    return 0;
}

