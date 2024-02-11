#ifndef LIST_H
#define LIST_H

template <typename T>
class Node
{
public:
    T m_value;
    Node* next = nullptr;

    Node() = default;
    explicit Node(T m_value) :m_value(m_value) {}
    explicit Node(T m_value, Node* next) :m_value(m_value), next(next) {}
};

template <typename T>
class List
{
public:
    Node<T>* m_head = nullptr;
    List() = default;
    ~List() = default;

    void push(int new_value);
    void insert(int pos, const T& value);
    void reverse();
    void print();
    bool is_circle();
    T find_n_in_end(int n);

};

#endif
