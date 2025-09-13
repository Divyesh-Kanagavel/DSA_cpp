// stack implementation with an array
/*
Functions
push, pop, isEmpty, Size
*/

#include <iostream>
#include <string>
#include <vector>

template <typename T>
class StackArray
{
    private:
        size_t m_size;
        size_t m_capacity;
        std::unique_ptr<T[]> m_arr;
    public:
        StackArray(size_t capacity)
        {
            m_arr = std::make_unique<T[]>(capacity);
            m_size = 0;
            m_capacity = capacity;
        }

        void push(T item)
        {
            if (m_size == m_capacity)
            {
                std::cout << "stack is full!\n";
                return;
            }
            m_arr[m_size++] = item;
        }

        T pop()
        {
            if (isEmpty())
            {
                std::cout << "Empty stack!\n";
                exit(EXIT_FAILURE);
            }
            return m_arr[--m_size];
        }

        bool isEmpty()
        {
            return m_size == 0;
        }

        size_t Size()
        {
            return m_size;
        }
};

int main()
{
    std::vector<std::string> S = {"to" ,"be", "or" ,"not","to", "-", "be", "-" ,"-", "that" ,"-", "-" ,"-" ,"is"};

    StackArray<std::string> stack(S.size());
    for (auto s : S)
    {
        if (s == "-")
        {
            std::cout << stack.pop() << " ";
        }
        else
        {
            stack.push(s);
        }
    }
    std::cout << std::endl;
    std::cout << "Size is : " << stack.Size() << std::endl;
}