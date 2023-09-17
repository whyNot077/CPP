#include "Span.hpp"

Span::Span(unsigned int capacity) : m_size(0), m_max(INT_MIN), m_min(INT_MAX) {
    if (capacity <= 0)
        throw std::runtime_error("Capacity must be greater than 0");
    if (capacity > 100000)
        throw std::runtime_error("Capacity must be less than 100000");
    m_capacity = capacity;
    m_numbers.reserve(m_capacity);
}

Span::Span(const Span& other) : m_capacity(other.m_capacity), m_size(other.m_size), m_max(other.m_max), m_min(other.m_min) {
    m_numbers.reserve(m_capacity);
    m_numbers = other.m_numbers;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        m_capacity = other.m_capacity;
        m_size = other.m_size;
        m_max = other.m_max;
        m_min = other.m_min;
        m_numbers.clear();
        m_numbers = other.m_numbers;
    }
    return *this;
}


std::vector<int>::iterator Span::begin() {
    return m_numbers.begin();
}

std::vector<int>::iterator Span::end() {
    return m_numbers.end();
}

void Span::addNumber(const int number) {
    if (m_size >= m_capacity)
        throw std::runtime_error("Span is full");
    if (number > m_max)
        m_max = number;
    else if (number < m_min)
        m_min = number;
    m_numbers.push_back(number);
    m_size++;
}

void Span::addNumber(const int number, const unsigned int size) {
    if (size <= 0)
        throw std::runtime_error("Size must be greater than 0");
    if (m_size + size > m_capacity)
        throw std::runtime_error("Span is full");
    if (number > m_max)
        m_max = number;
    else if (number < m_min)
        m_min = number;
    m_numbers.assign(size, number);
    m_size += size;
}

void Span::addNumber(const std::vector<int>::const_iterator start, \
                   const std::vector<int>::const_iterator end) {
    if (end - start <= 0)
        throw std::runtime_error("Iterator end is before or at iterator start");
    if (end - start + m_size > m_capacity)
        throw std::runtime_error("Span is full");
    for (std::vector<int>::const_iterator it = start; it < end; it++) {
        if (*it > m_max)
            m_max = *it;
        else if (*it < m_min)
            m_min = *it;
        m_numbers.push_back(*it);
        m_size++;
    }
}

#include <iostream>
int Span::shortestSpan() const {
    if (m_size <= 1)
        throw std::runtime_error("Span is empty or has only one element");
    std::vector<int> sorted_numbers = m_numbers;
    std::sort(sorted_numbers.begin(), sorted_numbers.end());
    int shortest_span = INT_MAX;
    for (unsigned int i = 0; i < m_size - 1; i++) {
        int span = abs(sorted_numbers[i + 1] - sorted_numbers[i]);
        if (span < shortest_span)
            shortest_span = span;
    }
    return shortest_span;
}

int Span::longestSpan() const {
    if (m_size <= 1)
        throw std::runtime_error("Span is empty or has only one element");
    return m_max - m_min;
}

unsigned int Span::getSize() const {
    return m_size;
}