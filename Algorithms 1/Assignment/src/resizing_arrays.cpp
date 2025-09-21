// stack implementation with an resizing array
/*
Functions
push, pop, isEmpty, Size
Based on amortized run time analysis
Resize array to twice the size when stack is full [repeated doubling]
Resize array to half the size when stack is quarter full
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

        void resize(size_t capacity)
        {
            auto new_arr = std::make_unique<T[]>(capacity);
            for(size_t i=0;i<m_size;i++)
            {
                new_arr[i] = m_arr[i];
            }
            m_arr = std::move(new_arr);
        }

        void push(T item)
        {          
            if (m_size == m_capacity)
            {
                resize(m_capacity * 2);
                m_capacity *= 2;

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
            if (m_size <= (m_capacity / 4))
            {
                resize(m_capacity / 2);
                m_capacity /= 2;
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

    StackArray<std::string> stack(S.size()/4);
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