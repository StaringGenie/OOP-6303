#include <assert.h>
#include <algorithm>
#include <stdexcept>
#include <cstddef>

#include <iostream>

namespace stepik
{
    template <class Type>
    struct node
    {
        Type value;
        node* next;
        node* prev;

        node(const Type& value, node<Type>* next, node<Type>* prev)
                : value(value), next(next), prev(prev)
        {
        }
    };

    template <class Type>
    class list; //forward declaration

    template <class Type>
    class list_iterator
    {
    public:
        typedef ptrdiff_t difference_type;
        typedef Type value_type;
        typedef Type* pointer;
        typedef Type& reference;
        typedef size_t size_type;
        typedef std::forward_iterator_tag iterator_category;

        list_iterator()
                : m_node(NULL)
        {
        }

        list_iterator(const list_iterator& other)
                : m_node(other.m_node)
        {
        }

        list_iterator(node<Type>* p)
                : m_node(p)
        {
        }

        node<Type>* getNode()
        {
            return m_node;
        }

        list_iterator& operator = (const list_iterator& other)
        {
            if (this != &other)
            {
                m_node = other.m_node;
            }
            return *this;
        }

        bool operator == (const list_iterator& other) const
        {
            return (m_node == other.m_node);
        }

        bool operator != (const list_iterator& other) const
        {
            return (m_node != other.m_node);
        }

        reference operator * ()
        {
            return m_node->value;
        }

        pointer operator -> ()
        {
            return &(m_node->value);
        }

        list_iterator& operator ++ ()
        {
            m_node = m_node->next;
            return *this;
        }

        list_iterator operator ++ (int)
        {
            list_iterator tmp(m_node);
            m_node = m_node->next;
            return tmp;
        }

        node<Type>* m_node;
    };

    template <class Type>
    class list
    {
    public:
        typedef Type value_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef list_iterator<Type> iterator;

        list()
                : m_head(nullptr), m_tail(nullptr)
        {
        }

        ~list()
        {
            clear();
        }

        iterator begin()
        {
            return iterator(m_head);
        }

        iterator end()
        {
            return iterator(m_tail);
        }

        list(const list& other)
        {
            if (!other.empty())
            {
                CopyList(other);
            }
            else
            {
                m_head = nullptr;
                m_tail = nullptr;
            }
        }

        list(list&& other)
        {
            if (!other.empty())
            {
                CopyList(other);
            }
            else
            {
                m_head = nullptr;
                m_tail = nullptr;
            }
            other.clear();
        }

        list& operator= (const list& other)
        {
            if (this != &other)
            {
                clear();
                if (!other.empty())
                {
                    CopyList(other);
                }
            }
            return *this;
        }

        void push_back(const value_type& value)
        {
            if (!empty())
            {
                node<value_type> *tmp = new node<value_type>(value, nullptr, m_tail);
                m_tail->next = tmp;
                m_tail = tmp;
            }
            else
            {
                m_head = new node<value_type>(value, nullptr, nullptr);
                m_tail = m_head;
            }
        }

        void push_front(const value_type& value)
        {
            if (!empty())
            {
                node<value_type> *tmp = new node<value_type>(value, m_head, nullptr);
                m_head->prev = tmp;
                m_head = tmp;
            }
            else
            {
                m_head = new node<value_type>(value, nullptr, nullptr);
                m_tail = m_head;
            }
        }

        reference front()
        {
            return m_head->value;
        }

        const_reference front() const
        {
            return m_head->value;
        }

        reference back()
        {
            return m_tail->value;
        }

        const_reference back() const
        {
            return m_tail->value;
        }

        void pop_front()
        {
            if (!empty())
            {
                node<Type>* tmp = m_head->next;
                delete m_head;
                m_head = tmp;
                if (!empty())
                {
                    m_head->prev = nullptr;
                }
            }
        }

        void pop_back()
        {
            if (!empty())
            {
                node<Type>* tmp = m_tail->prev;
                delete m_tail;
                m_tail = tmp;
                if (m_tail)
                {
                    m_tail->next = nullptr;
                }
                else
                {
                    m_head = m_tail;
                }
            }
        }

        void clear()
        {
            while (m_head)
            {
                pop_front();
            }
            m_tail = nullptr;
        }

        bool empty() const
        {
            return !(m_head);
        }

        size_t size() const
        {
            size_t count = 0;
            node<Type>* tmp = m_head;
            while (tmp)
            {
                count++;
                tmp = tmp->next;
            }
            return count;
        }

        void printList()
        {
            node<Type>* tmp = m_head;
            while (tmp)
            {
                std::cout << tmp->value << " ";
                tmp = tmp->next;
            }
            std::cout << std::endl;
            std::cout << "Size: " << size() << std::endl;
            std::cout << std::endl;
        }

        iterator insert(iterator pos, const Type& value)
        {
            iterator tmp(m_head);
            while (tmp != pos)
            {
                tmp++;
            }
            node <value_type> *elem = new node <Type>(value, tmp.getNode(), tmp.getNode()->prev);
            tmp.getNode()->prev = elem;
            tmp = elem->prev;
            if (tmp.getNode())
                tmp.getNode()->next = elem;
            while (m_head->prev)
                m_head = m_head->prev;
            return iterator(elem);
        }

        iterator erase(iterator pos)
        {
            iterator next_pos = pos.getNode()->next;
            node<Type> *f_free = pos.getNode();
            if (f_free == m_head)
            {
                m_head = m_head->next;
                m_head->prev = nullptr;
            }
            else
            {
                if (f_free == m_tail)
                {
                    m_tail = m_tail->prev;
                    m_tail->next = nullptr;
                }
                else
                {
                    f_free->next->prev = f_free->prev;
                    f_free->prev->next = f_free->next;
                }
            }
            delete [] f_free;
            return next_pos;
        }

    private:
        //your private functions
        void CopyList(const list& other)
        {
            node<value_type> *element = other.m_head;
            m_head = new node<value_type>(element->value, nullptr, nullptr);
            node<value_type> *m_element = m_head;
            node<value_type> *tmp = nullptr;
            while (element->next)
            {
                element = element->next;
                tmp = new node<value_type>(element->value, nullptr, m_element);
                m_element->next = tmp;
                m_element = tmp;
            }
            m_tail = tmp;
        }


        node<Type>* getHead()
        {
            return m_head;
        }

        node<Type>* getTail()
        {
            return m_tail;
        }

        node<Type>* m_head;
        node<Type>* m_tail;
    };

}// namespace stepik