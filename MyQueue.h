#pragma once

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <tuple>
#include <memory>
#include <queue>

template<typename T>
class MyQueue
{
    T **m_data;
    int count;
    int capacity;
    public:
    MyQueue():
    count{0},
    capacity{MAX_ARRAY},
    m_data{new T*[MAX_ARRAY]}
    {
    }
    ~MyQueue()
    {
        count = 0;
        capacity = 0;
        delete[] m_data;
    }
    void push(T newvalue);
    T& top() const;
    void pop();
    int size() const
	{
		return count;
	}
    MyQueue(MyQueue& rhs);
    MyQueue& operator = (MyQueue& rhs);
    MyQueue(MyQueue&& rhs);
    MyQueue& operator = (MyQueue&& rhs);
    void clear();

    void printValues()
    {
        for(int i=0;i<capacity;++i)
        {
            std::cout << "value:"<< top()->my_int_data << std::endl;
            pop();
        }
    }
};
