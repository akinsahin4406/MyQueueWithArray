#include <iostream>
#include "MyQueue.h"

template<typename T>
void MyQueue<T>::push(T newvalue)
{
    if (count == capacity)
    {
        capacity *= 2;
        T **ptr = m_data;
        m_data = new T*[capacity];
        for(int i=0;i<count;++i)
        {
            m_data[i] = ptr[i];
        }
        delete[] ptr;
    }
    ++count;
    m_data[count-1] = new T(newvalue);
}

template<typename T>
T& MyQueue<T>::top() const
{
    T *ret = m_data[0];
    return *ret;
}

template<typename T>
void MyQueue<T>::pop()
{
    T **ptr = m_data;
    T this_one = *m_data[0];
    delete this_one;
    --count;
    for(int j=0;j<count;++j)
    {
        m_data[j] = ptr[j+1];
    }
    m_data[count] = nullptr;
}

template<typename T>
MyQueue<T>::MyQueue(MyQueue& rhs):
capacity{rhs.capacity},
count{rhs.count},
m_data{new T[capacity]}
{
    for(int j=0;j<count;++j)
    {
        m_data[j] = rhs.m_data[j];
    }
}

template<typename T>
MyQueue<T>& MyQueue<T>::operator = (MyQueue& rhs)
{
    if (this != &rhs)
    {
        if (capacity != rhs.capacity)
        {
            delete[] m_data;
            m_data = new T[rhs.capacity];
        }
        capacity = rhs.capacity;
        count = rhs.count;
        for(int i=0;i<count;++i)
        {
            m_data[i] = rhs.m_data[i];
        }
    }
    return *this;
}

template<typename T>
MyQueue<T>::MyQueue(MyQueue&& rhs)
{
    delete[] m_data;
    count = rhs.count;
    capacity = rhs.capacity;
    m_data = rhs.m_data;
    rhs.m_data = nullptr;
    rhs.count = 0;
    rhs.capacity = 0;
}

template<typename T>
MyQueue<T>& MyQueue<T>::operator = (MyQueue&& rhs)
{
    if (this != &rhs)
    {
        delete[] m_data;
        count = rhs.count;
        capacity = rhs.capacity;
        m_data = rhs.m_data;
        rhs.m_data = nullptr;
        rhs.count = 0;
        rhs.capacity = 0;
    }
} 

template<typename T>
void MyQueue<T>::clear() 
{
    for (int i=0;i<count;i++)
    {
        T this_one = *m_data[count-1];
        delete this_one;
    }
    m_data = nullptr;
    capacity =0;
    count = 0;

}
