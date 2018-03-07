#include <assert.h>
#include <algorithm> // std::copy
#include <cstddef> // size_t
#include <memory>

using namespace std;

template<typename T>
class Array
{
public:
  // (default) constructor
  Array(const size_t size = 0)
    : m_size(size)
    , m_array(m_size ? new T[m_size]() : nullptr)
  {
  }
//конструктор копирования
  Array(const Array& other_obj)   : m_size(other_obj.m_size),   m_array(m_size ? new T[m_size] : nullptr)  {
      copy(other_obj.m_array.get(), other_obj.m_array.get() + m_size, m_array.get());
  }

  //оператор присваивания
Array & operator=(Array obj){
  swap(m_size, obj.m_size);
  swap(m_array, obj.m_array);
  return *this;
 }


//конструктор перемещения
 Array(Array&& obj) :
  m_size(obj.m_size),
  m_array(m_size ? new T[m_size]() : nullptr){
  copy(obj.m_array.get(), obj.m_array.get() + m_size, m_array.get());
 }



  const size_t size() const
  {
    return m_size;
  }

  T& operator [](const size_t index)
  {
    assert(index < m_size);

    return m_array[index];
  }

private:
  size_t m_size;
  unique_ptr <T[]> m_array;
};
