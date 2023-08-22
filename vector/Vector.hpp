#pragma once

#include <iostream>
#include <exception>

template<typename T>
class Vector
{
    private:
        
        T* m_array = nullptr;
        int m_capacity = 0;
        int m_size = 0;


    public:
        Vector();
        ~Vector();
        T* get();
        int capacity()const;
        int size()const;
        void print()const;
        void reserve(int size);
        void push_back(T value);
        void insert_(int index, T element);
        T at(int index)const;
        bool empty()const;
        void pop_back();
        void pop_front();
        void insert(int index, T value);
        void erase(int index);
        T* end();
};