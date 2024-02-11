
#include "List.h"
#include <iostream>

template class Node<int>; // Example with double
template class Node<double>; // Example with double

template class List<int>; // Example with int
template class List<double>; // Example with double

template <typename T>
void List<T>::push(int new_value)
{
    Node<T>* new_node = new Node<T>(new_value);
    if (!m_head) {
        m_head = new_node;
        return;
    }

    new_node->next = m_head;
    m_head = new_node;
}
template <typename T>
void List<T>::pop() {
    if (!m_head) {
        return;
    }

    if (!m_head->next) {
        delete m_head;
        m_head = nullptr;
        return;
    }

    Node<T>* new_node = m_head;
    while (new_node->next->next) {
        new_node = new_node->next;
    }
    delete new_node->next;
    new_node->next = nullptr;
}

template <typename T>
void List<T>::reverse()
{
    Node<T>* prev = nullptr;
    Node<T>* current = this->m_head;
    Node<T>* next = nullptr;
    while (current->next != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    next->next = prev;
    prev = next;
    this->m_head = prev;

}

template <typename T>
void List<T>::print()
{
    Node<T>* temp = this->m_head;
    while (temp)
    {
        std::cout << temp->m_value << std::endl;
        temp = temp->next;
    }
    std::cout << std::endl;
}

template <typename T>
T List<T>::find_n_in_end(int n)
{
    Node<T>* temp = m_head;

    for (int i = 1; i < n; i++)
    {
        if (m_head->next != nullptr)
        {
            m_head = m_head->next;
        }
    }

    while (m_head->next != nullptr)
    {
        m_head = m_head->next;
        temp = temp->next;
    }

    return temp->m_value;
}


