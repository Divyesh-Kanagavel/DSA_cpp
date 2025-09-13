// Implementation of stack data structure in C++
/*
Uses linked list with generic data types supported in C++
Gives access to the following APIs - 
push, pop, Size, isEmpty()
*/

#include <string>
#include <vector>
#include <memory>
#include <iostream>

template <typename T>
struct Node
{
   T item;
   std::unique_ptr<Node<T>> next;
};

template <typename T>
class Stack
{
    public:
    // constructor
    Stack()
    {
        m_first = nullptr;
        m_size = 0;
    }

    bool isEmpty() const
    {
        return m_size == 0;
    }

    void push(T item)
    {
        auto new_node = std::make_unique<Node<T>>();
        new_node->item = item;

        new_node->next = std::move(m_first);
        m_first = std::move(new_node);
        ++m_size;
    }

    T pop()
    {
        if (isEmpty())
        {
            std::cout << "Empty stack!\n";
            exit(EXIT_FAILURE);
        }
        T item = m_first->item;
        auto old_first = std::move(m_first->next);
        m_first = std::move(old_first);
        --m_size;
        return item;
    }

    size_t Size()
    {
        return m_size;
    }


    private:
        std::unique_ptr<Node<T>> m_first;
        size_t m_size;
};

// verification of an implementation using a client


int main()
{
    std::vector<std::string> S = {"to" ,"be", "or" ,"not","to", "-", "be", "-" ,"-", "that" ,"-", "-" ,"-" ,"is"};

    Stack<std::string> stack;
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

