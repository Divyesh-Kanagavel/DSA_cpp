// Implementation of queue using two stacks

#include <iostream>
#include <memory>

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

template <typename T>
class Queue_2Stack
{
    public:
        Queue_2Stack(size_t capacity) : m_stack1 {capacity}, m_stack2 {capacity}
        {}   

        void enqueue(T item)
        {
            m_stack1.push(item);
        }

        T dequeue()
        {
            if (m_stack2.isEmpty())
            {
                while(!m_stack1.isEmpty())
                {
                    T item = m_stack1.pop();
                    m_stack2.push(item);
                }
                return m_stack2.pop();
            }
            else
            {
                return m_stack2.pop();
            }
        }

        bool isEmpty() const
        {
            return (m_stack1.isEmpty() && m_stack2.isEmpty());
        }

        size_t Size() const
        {
            return m_stack1.Size() + m_stack2.Size();
        }

    private:
        StackArray<T> m_stack1;
        StackArray<T> m_stack2;
};

int main()
{
    Queue_2Stack<int> qs(10);
    qs.enqueue(19);
    qs.enqueue(21);
    qs.enqueue(24);
    std::cout << qs.dequeue() << std::endl;
    qs.enqueue(31);
    std::cout << qs.dequeue() << std::endl;
    std::cout << qs.dequeue() << std::endl;
    return 0;

}