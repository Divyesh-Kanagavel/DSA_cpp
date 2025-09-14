/*
Efficient implementation of a stack in c++ with maximum of stack computed.
*/

#include <iostream>
#include <memory>
#include <algorithm>

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
        // returns the top of the stack
        T top() const
        {
            if (m_size > 0)
                return m_arr[m_size-1];
            else
                return m_arr[m_size];
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

template <typename T>
class MaxStack
{
    public:
        MaxStack(size_t capacity) : m_valStack {capacity}, m_maxStack {capacity}
        {}

        void push(T item)
        {
            m_valStack.push(item);
            m_maxStack.push(std::max(item, m_maxStack.top()));
        }

        T pop()
        {
            T item = m_valStack.pop();
            T max = m_maxStack.pop();
            return item;
        }

        bool isEmpty() const
        {
            return m_valStack.Size() == 0;
        }

        size_t Size() const
        {
            return m_valStack.Size();
        }

        T maxVal() const
        {
            return m_maxStack.top();
        }

    private:
        StackArray<T> m_valStack;
        StackArray<T> m_maxStack;
};

int main()
{
    MaxStack<int> ms(10);
    ms.push(5);
    ms.push(10);
    ms.push(12);
    std::cout << ms.maxVal() << std::endl;
    ms.pop();
    std::cout << ms.maxVal() << std::endl;
    ms.push(3);
    ms.push(14);
    ms.pop();
    ms.push(13);
    std::cout << ms.maxVal() << std::endl;
}