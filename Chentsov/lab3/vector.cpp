#include <assert.h>
#include <algorithm> // std::copy, std::rotate
#include <cstddef> // size_t
#include <initializer_list>
#include <stdexcept>

namespace stepik
{
    template <typename Type>
    class vector
    {
    public:
        typedef Type* iterator;
        typedef const Type* const_iterator;

        typedef Type value_type;

        typedef value_type& reference;
        typedef const value_type& const_reference;

        typedef std::ptrdiff_t difference_type;

        explicit vector(size_t count = 0)
                : m_first(new Type[count]), m_last(m_first+count)
        {}

        template <typename InputIterator>
        vector(InputIterator first, InputIterator last)
                : m_first(new Type[last-first]), m_last(m_first+(last-first))
        {
            std::copy(first, last, m_first);
        }

        vector(std::initializer_list<Type> init)
                : m_first(new Type[init.size()]), m_last(m_first+init.size())
        {
            std::copy(init.begin(), init.end(), m_first);
        }

        vector(const vector& other)
                : m_first(new Type[other.size()]), m_last(m_first+other.size())
        {
            std::copy(other.begin(), other.end(), m_first);
        }

        vector(vector&& other): m_first(other.m_first), m_last(other.m_last)
        {
            other.m_first = nullptr;
            other.m_last = nullptr;
        }

        ~vector()
        {
            if(!empty())
                delete [] m_first;
        }

        //assignment operators
        vector& operator=(const vector& other)
        {
            if (this != &other)
            {
                if(!empty())
                    delete [] m_first;
                m_first = nullptr;
                m_last = nullptr;
                if(other.size() > 0)
                {
                    m_first = new Type[other.size()];
                    m_last = m_first + other.size();
                    std::copy(other.begin(), other.end(), m_first);
                }
            }
            return *this;
        }

        vector& operator=(vector&& other)
        {
            if(this != &other)
            {
                if(!empty())
                    delete [] m_first;
                m_first = other.m_first;
                m_last = other.m_last;
                other.m_first = nullptr;
                other.m_last = nullptr;
            }
            return *this;
        }

        // assign method
        template <typename InputIterator>
        void assign(InputIterator first, InputIterator last)
        {
            if(!empty())
            {
                delete []m_first;
                m_first = nullptr;
                m_last = nullptr;
            }
            if(last-first > 0)
            {
                m_first = new Type[last-first];
                m_last = m_first+(last-first);
                std::copy(first, last, m_first);
            }
        }

        // resize methods
        void resize(size_t count)
        {
            if(count != 0)
            {
                int delta = count - (m_last - m_first);
                if(delta > 0)
                {
                    iterator tmp = new Type[count];
                    std::copy(m_first, m_last, tmp);
                    if(!empty())
                        delete [] m_first;
                    m_first = tmp;
                    m_last = m_first + count;
                }
                else
                {
                    m_last = m_last + delta;
                }
            }
            else
            {
                m_last = m_first;
                delete [] m_first;
            }
        }

        //erase methods
        iterator erase(const_iterator pos)
        {
            size_t offset = pos - m_first;
            std::rotate(m_first + offset, m_first + offset + 1, m_last);
            resize(m_last - m_first -1);
            return m_first + offset;
        }

        iterator erase(const_iterator first, const_iterator last)
        {
            size_t offset = first - m_first;
            size_t length = last - first;
            std::rotate(m_first + offset, m_first + offset + length, m_last);
            resize(m_last - m_first - length);
            return m_first + offset;
        }

        //insert methods
        iterator insert(const_iterator pos, const Type& value)
        {
            size_t offset = pos - m_first;
            push_back(value);
            std::rotate(m_first + offset, m_last-1, m_last);
            return m_first + offset;
        }

        template <typename InputIterator>
        iterator insert(const_iterator pos, InputIterator first, InputIterator last)
        {
            size_t offset = pos - m_first;
            size_t length = last - first;
            size_t _size = size();
            iterator tmp = new Type[_size+length];
            std::copy(m_first, m_last, tmp);
            std::copy(first, last, tmp + _size);
            std::rotate(tmp + offset, tmp + _size, tmp + _size + length);
            if(!empty())
                delete [] m_first;
            m_first = tmp;
            m_last = tmp + _size + length;
            return m_first + offset;
        }

        //push_back methods
        void push_back(const value_type& value)
        {
            size_t _size = size();
            iterator tmp = new Type[_size+1];
            std::copy(m_first, m_last, tmp);
            if (!empty())
                delete [] m_first;
            m_first = tmp;
            m_last = m_first + _size + 1;
            *(m_last-1) = value;
        }

        //at methods
        reference at(size_t pos)
        {
            return checkIndexAndGet(pos);
        }

        const_reference at(size_t pos) const
        {
            return checkIndexAndGet(pos);
        }

        //[] operators
        reference operator[](size_t pos)
        {
            return m_first[pos];
        }

        const_reference operator[](size_t pos) const
        {
            return m_first[pos];
        }

        //*begin methods
        iterator begin()
        {
            return m_first;
        }

        const_iterator begin() const
        {
            return m_first;
        }

        //*end methods
        iterator end()
        {
            return m_last;
        }

        const_iterator end() const
        {
            return m_last;
        }

        //size method
        size_t size() const
        {
            return m_last - m_first;
        }

        //empty method
        bool empty() const
        {
            return m_first == m_last;
        }

    private:
        reference checkIndexAndGet(size_t pos) const
        {
            if (pos >= size())
            {
                throw std::out_of_range("out of range");
            }

            return m_first[pos];
        }

        //your private functions

    private:
        iterator m_first;
        iterator m_last;
    };
}// namespace stepik