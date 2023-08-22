#include "Vector.hpp"

template <typename T>
Vector<T>::Vector(){}

template <typename T>
Vector<T>::~Vector()
{
    delete[] m_array;
}

template <typename T>
T* Vector<T>::get()
{
    return m_array;
}

template <typename T>
int Vector<T>::capacity() const
{
    return m_capacity;
}

template <typename T>
int Vector<T>::size() const
{
    return m_size;
}

template <typename T>
void Vector<T>::print() const
{
    for (int i = 0; i < m_size; ++i)
    {
        std::cout << m_array[i];
    }
    std::cout << std::endl;
}

template <typename T>
void Vector<T>::reserve(int size)
{
    if (m_array == nullptr)
    {
        m_array = new T[size];
    }
    else
    {
        T* tmp = new T[m_capacity + size];
        for (int i = 0; i < m_size; ++i)
        {
            tmp[i] = m_array[i];
        }
        delete[] m_array;
        m_array = tmp;
    }
    m_capacity += size;
}

template <typename T>
void Vector<T>::push_back(T value)
{
    reserve(1);
    m_array[m_size] = value;
    ++m_size;
}

template <typename T>
void Vector<T>::insert_(int index, T element)
{
    if (index >= 0 && index <= m_capacity)
    {
        m_array[index] = element;
    }
    else
    {
        std::cout << "Error: Invalid index" << std::endl;
    }
}

template <typename T>
T Vector<T>::at(int index)const
{
    if (index >= 0 && index < m_size)
    {
        return m_array[index];
    }
    return T(); 
}

template <typename T>
bool Vector<T>::empty() const
{
    return m_size == 0;
}

template <typename T>
void Vector<T>::pop_back()
{
    if (m_size > 0)
    {
        --m_size;
    }
}

template <typename T>
void Vector<T>::pop_front()
{
    if (m_size > 0)
    {
        for (int i = 1; i < m_size; ++i)
        {
            m_array[i - 1] = m_array[i];
        }
        --m_size;
    }
}

template <typename T>
void Vector<T>::insert(int index, T value)
{
    if (index >= 0 && index <= m_size)
    {
        reserve(1);
        for (int i = m_size; i > index; --i)
        {
            m_array[i] = m_array[i - 1];
        }
        m_array[index] = value;
        ++m_size;
    }
}

template <typename T>
void Vector<T>::erase(int index)
{
    if (index >= 0 && index < m_size)
    {
        for (int i = index; i < m_size - 1; ++i)
        {
            m_array[i] = m_array[i + 1];
        }
        --m_size;
    }
}

template <typename T>
T* Vector<T>::end()
{
    if (m_size > 0)
    {
        return &m_array[m_size - 1];
    }
    throw std::runtime_error("Vector is empty");
}