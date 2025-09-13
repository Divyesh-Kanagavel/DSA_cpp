// Queue data structure implementation in C++ using arrays
/*
push : resizing arrays
pop : resizing arrays
isEmpty()
Size()
*/

#include <vector>
#include <iostream>

template <typename T>
class QueueArray
{

    public:
    QueueArray(size_t capacity) : m_capacity {capacity}, m_size {0}
    {
        m_head = 0;
        m_tail = 0;
        m_arr = new T[capacity];
    }

    void resize(size_t capacity)
    {
        T* new_arr = new T[capacity];
        for(size_t i=0;i<m_size;i++)
        {
            new_arr[i] = m_arr[(m_head + i)%m_capacity];
        }
        m_head = 0;
        m_tail = m_size;
        delete[] m_arr;
        m_arr = new_arr;
    }

    void enqueue(T item)
    {
        if (m_size == m_capacity)
        {
            std::cout << "increasing capacity for enqueue() to " << m_capacity * 2 << " from " << m_capacity << std::endl;
            resize(m_capacity * 2);
            m_capacity *= 2;
        }
        m_arr[m_tail] = item;
        m_tail = (m_tail + 1) % m_capacity;
        m_size++;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Empty stack!\n";
            exit(EXIT_FAILURE);
        }
        if (m_size <= m_capacity / 4)
        {
            std::cout << "decreasing capacity for dequeue() to " << m_capacity / 2 << "from " << m_capacity << std::endl;
            resize(m_capacity / 2);
            m_capacity /= 2;
        }
        T item = m_arr[m_head];
        m_head = (m_head + 1) % m_capacity;
        m_size--;
        return item;       
    }

    bool isEmpty()
    {
        return m_size == 0;
    }

    size_t Size()
    {
        return m_size;
    }

    ~QueueArray()
    {
        delete[] m_arr;
    }

    private:
        size_t m_capacity;
        size_t m_size;
        T* m_arr;
        size_t m_head;
        size_t m_tail;
        
};

int main()
{
    std::vector<int> a = {1,3,4,5,10,11,12,13,14,15};
    QueueArray<int> queue(4);
    queue.enqueue(a[0]);
    queue.enqueue(a[1]);
    queue.enqueue(a[2]);
    std::cout << queue.dequeue() << std::endl;
    queue.enqueue(a[3]);
    queue.enqueue(a[4]);
    queue.enqueue(a[5]);
    queue.enqueue(a[6]);
    queue.enqueue(a[7]);
    queue.enqueue(a[8]);
    queue.enqueue(a[9]);
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
}