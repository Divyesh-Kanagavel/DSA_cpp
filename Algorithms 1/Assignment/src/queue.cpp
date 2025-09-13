// Queue data structure in C++
/*
APIs
Enqueue, Dequeue, Size, isEmpty 
*/
#include <vector>
#include <iostream>
template <typename T>
struct Node
{
   T item;
   Node<T> *next;
};

template <typename T>
class Dequeue
{
    public:
    Dequeue() : m_first{nullptr}, m_last{nullptr}, m_size {0}
    {}

    void enqueue(T item)
    {
        Node<T> *oldLast = m_last;

        Node<T> *new_node = new Node<T>();
        new_node->item = item;
        new_node->next = nullptr;
        
        m_last = new_node;

        if (isEmpty())
        {
            m_first = m_last;
        }
        else
        {
            oldLast->next = m_last;
        }
        m_size++;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Empty stack!\n";
            exit(EXIT_FAILURE);
        }
        T item = m_first->item;
        m_first = m_first->next;
        m_size--;
        if (isEmpty())
            m_last = nullptr;
        return item;        
    }

    bool isEmpty() const
    {
        return m_size == 0;
    }

    size_t Size() const
    {
        return m_size;
    }

    ~Dequeue()
    {
        Node<T> *head = m_first;
        while(head != nullptr)
        {
            Node<T> *next_node = head->next;
            delete head;
            head = next_node;
;
        }
        m_first=nullptr;
        m_last=nullptr;
    }

    private:
        size_t m_size;
        Node<T> *m_first;
        Node<T> *m_last;

};

int main()
{
    std::vector<int> a = {1,3,4,5,10,11,12};
    Dequeue deq = Dequeue<int>();
    deq.enqueue(a[0]);
    deq.enqueue(a[1]);
    deq.enqueue(a[2]);
    std::cout << deq.dequeue() << std::endl;
    deq.enqueue(a[3]);
    deq.enqueue(a[4]);
    std::cout << deq.dequeue() << std::endl;
    std::cout << deq.dequeue() << std::endl;
    std::cout << deq.dequeue() << std::endl;
    return 0;
}