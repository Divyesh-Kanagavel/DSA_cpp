// Double ended queue implementation
// combination of stack and queue

#include <iostream>

template <typename T>
class Deque
{
    public:
    // constructor
    Deque(size_t capacity) : m_capacity {capacity}, m_size {0}
    {
        m_arr = new T[capacity];
        m_head = 0;
        m_tail = 0;
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

    void addFirst(T item)
    {
        if (m_size == m_capacity)
        {
            std::cout << "increasing capacity from " << m_capacity << " to " << m_capacity * 2 << std::endl;
            resize(m_capacity * 2);
            m_capacity *= 2;
        }
        m_head = (m_head - 1 + m_capacity) % m_capacity; // wrap around for circular buffer
        m_arr[m_head] = item;
        m_size++;

    }

    void addLast(T item)
    {
        if (m_size == m_capacity)
        {
            std::cout << "increasing capacity from " << m_capacity << " to " << m_capacity * 2 << std::endl;
            resize(m_capacity * 2);
            m_capacity *= 2;
        }
        m_arr[m_tail] = item;
        m_tail = (m_tail + 1) % m_capacity;
        m_size++;
    }

    T removeFirst()
    {
        if (m_size == 0)
        {
            std::cout << "Empty deque!\n";
            exit(EXIT_FAILURE);
        }
        if (m_size <= m_capacity / 4)
        {
            std::cout << "decreasing capacity from " << m_capacity << " to " << m_capacity / 2 << std::endl;
            resize(m_capacity / 2);
            m_capacity /= 2;
        }
        T item = m_arr[m_head];
        m_head = (m_head + 1) % m_capacity;
        m_size--;
        return item;
    }

    T removeLast()
    {
        if (m_size == 0)
        {
            std::cout << "Empty deque!\n";
            exit(EXIT_FAILURE);
        }
        if (m_size <= m_capacity / 4)
        {
            std::cout << "decreasing capacity from " << m_capacity << " to " << m_capacity / 2 << std::endl;
            resize(m_capacity / 2);
            m_capacity /= 2;  
        }
        m_tail = (m_tail - 1 + m_capacity) % m_capacity;
        T item = m_arr[m_tail];
        m_size--;
        return item;
    }

    size_t Size() const
    {
        return m_size;
    }

    bool isEmpty() const
    {
        return m_size == 0;
    }

    ~Deque()
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
    Deque<int> deq(10);
    deq.addFirst(4);
    deq.addFirst(8);
    deq.addFirst(9);
    deq.addLast(10);
    deq.addFirst(11);
    deq.addFirst(18);
    deq.addLast(14);
    deq.addLast(19);
    deq.addLast(21);
    deq.addFirst(22);
    deq.addLast(24);
    deq.addLast(25);
    deq.addFirst(30);
    std::cout << deq.removeFirst() << std::endl;
    std::cout << deq.removeLast() << std::endl;
    std::cout << deq.removeLast() << std::endl;
    std::cout << deq.removeLast() << std::endl;
    std::cout << deq.removeLast() << std::endl;
    std::cout << deq.removeLast() << std::endl;
    std::cout << deq.removeLast() << std::endl;
    std::cout << deq.removeLast() << std::endl;
    std::cout << deq.removeLast() << std::endl;
    std::cout << deq.removeLast() << std::endl;
    std::cout << deq.removeFirst() << std::endl;
    std::cout << deq.removeFirst() << std::endl;
    std::cout << deq.removeFirst() << std::endl;

}