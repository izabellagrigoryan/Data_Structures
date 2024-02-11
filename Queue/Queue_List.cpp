// Queue_List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "List.h"
#include <iostream>

template <typename T>

class Queue :public List<T>
{
public:
    Queue<T>() = default;
    ~Queue<T>() = default;
};

int main()
{
    Queue<int> m_queue;
    m_queue.push(11);
    m_queue.push(22);
    m_queue.push(33);
    m_queue.push(44);
    m_queue.push(55);
    m_queue.push(66);
    m_queue.push(77);
    m_queue.push(88);
    m_queue.push(99);
    m_queue.print();

    m_queue.pop();
    m_queue.pop();
    m_queue.pop();
    m_queue.print();
}
