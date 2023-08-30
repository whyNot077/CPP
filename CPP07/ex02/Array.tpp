#ifndef ARRAT_TPP
#define ARRAT_TPP

template <typename T>
Array<T>::Array() : m_array(new T[0]), m_size(0) { }

template <typename T>
Array<T>::Array(unsigned int n) : m_array(new T[n]), m_size(n) { }

template <typename T>
Array<T>::Array(Array const & src) : m_array(new T[src.m_size]), m_size(src.m_size) {
    for (unsigned int i = 0; i < m_size; ++i)
        m_array[i] = src.m_array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(Array const & other) {
    if (this != &other) {
        // delete[] m_array;
        // m_size = other.m_size;
        // m_array = new T[m_size];
        // for (unsigned int i = 0; i < m_size; ++i)
        //     m_array[i] = other.m_array[i];
        this->~Array();
        new (this)Array(other);
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= m_size)
        throw std::out_of_range("Array index out of bounds");
    return m_array[index];
}

template <typename T>
T const& Array<T>::operator[](unsigned int index) const {
    if (index >= m_size)
        throw std::out_of_range("Array index out of bounds");
    return m_array[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return m_size;
}

template <typename T>
Array<T>::~Array() {
    delete[] m_array;
}

#endif