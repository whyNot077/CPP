#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array {
private:
    T* m_array;
    unsigned int m_size;

public:
    Array();
    Array(unsigned int n);
    Array(Array const & src);
    Array & operator=(Array const & other);
    T & operator[](unsigned int index);
    T const & operator[](unsigned int index) const;
    unsigned int size() const;
    ~Array();
};

#include "Array.tpp"

#endif