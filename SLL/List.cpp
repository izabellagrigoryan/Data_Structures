
#include "List.h"
#include <iostream>

template class Node<int>; 
template class List<int>;

template <typename T>
void List<T>::push(int new_value)
{
    Node<T>* new_node = new Node<T>(new_value);

    new_node->next = m_head;
    m_head = new_node;
}

template <typename T>
void List<T>::insert(int pos, const T& value)
{
    Node<T>* temp = m_head;

    for (int i = 0; i < pos; i++)
    {
        if (temp->next != nullptr)

            temp = temp->next;
    }
    Node<T>* temp_next = new Node<T>(value, temp);
    m_head->next = temp_next;

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
bool List<T>::is_circle()
{
    Node<T>* prev = m_head;
    Node<T>* current = m_head->next;
    
    while (current->next != nullptr)
    {
        if (current->next == prev)
        {
            return true;
        }
        current = current->next;
        prev = prev->next;
    }

    return false;
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


