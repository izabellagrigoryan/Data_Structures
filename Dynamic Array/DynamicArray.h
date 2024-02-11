#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template <typename T>

class DynamicArray {

public:
    explicit DynamicArray() noexcept;
    ~DynamicArray() noexcept;
    
    int get_size();
    void push_back(T element);
    void pop_back();
    void pop_front(T element);
    void insert(T element, int position);
    void shrink_to_fit();
    void erase(int element);
    void print();

private:
    size_t m_capacity;
    size_t m_size;
    T* m_ptr;
};

#endif