// DynamicArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "DynamicArray.h"
#include <iostream>

template class DynamicArray<int>; 

template <typename T>
DynamicArray<T>::DynamicArray() noexcept
{
    m_capacity = 1;
    m_size = 0;
    m_ptr = new T[m_capacity];
}

template <typename T>
DynamicArray<T>::~DynamicArray() noexcept
{
    delete[] m_ptr;
};

template <typename T>
void DynamicArray<T>::push_back(T element)
{   
    if (m_size == m_capacity)
    {
        m_capacity *= 2;
        T* temp = new T[m_capacity];
        for (int i = 0; i < m_size; i++)
            temp[i] = m_ptr[i];

        delete[] m_ptr;
        m_ptr = temp;
    }
    m_ptr[m_size] = element;
    m_size++;
};

template <typename T>
void DynamicArray<T>::pop_back()
{
    m_size--;
}

template <typename T>
void DynamicArray<T>::pop_front(T element)
{       
    if (m_size == m_capacity)
    {
        m_capacity *= 2;
        T* temp = new T[m_capacity];
        temp[0] = element;
        for (int i = 0; i < m_size; i++)
            temp[i + 1] = m_ptr[i];

        delete[] m_ptr;
        m_ptr = temp;
    }
    else
    {
        T* temp = new T[m_capacity];
        temp[0] = element;
        for (int i = 0; i < m_size; i++)
            temp[i + 1] = m_ptr[i];

        delete[] m_ptr;
        m_ptr = temp;
    }
}

template <typename T>
void DynamicArray<T>::insert(T element, int position)
{
    if (m_size == m_capacity)
    {
        m_capacity *= 2;
        T* temp = new T[m_capacity];

        for (int i = 0; i < m_size; i++)
            temp[i] = m_ptr[i];

        delete[] m_ptr;
        m_ptr = temp;
    }

    for (int i = m_size; i > position; i--)
    
        m_ptr[i] = m_ptr[i - 1];
    
    m_ptr[position] = element;
    m_size++;
}

template <typename T>
void DynamicArray<T>::shrink_to_fit()
{
    if (m_size == m_capacity/4)
    {
        T* temp = new T[m_capacity/2];

        for (int i = 0; i < m_size; i++)
            temp[i] = m_ptr[i];

        m_capacity /= 2;
        delete[] m_ptr;
        m_ptr = temp;
    }

}

template <typename T>
void DynamicArray<T>::erase(int element)
{
    for (int i = element - 1; i < m_size - 1; i++)
        m_ptr[i] = m_ptr[i + 1];

    m_size--;
};

template <typename T>
void DynamicArray<T>::print()
{
    for (int i = 0; i < m_size; i++)
        std::cout << m_ptr[i] << ",  ";
    std::cout << std::endl;

    std::cout << "Capacity = " << m_capacity << std::endl;
    std::cout << "Size = " << m_size << std::endl;
}

template <typename T>
int DynamicArray<T>::get_size()
{
    return m_size;
}

int main()
{
    std::cout << "Hello World!\n";
}
