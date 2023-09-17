#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <stdexcept>
#include <vector>
#include <climits>

class Span {
private:
    Span() {}
    unsigned int m_capacity;
    unsigned int m_size;
    std::vector<int> m_numbers;
    int m_max;
    int m_min;

public:
    ~Span() {}
    Span(const unsigned int capacity);
    Span(const Span& other);
    Span& operator=(const Span& other);
    std::vector<int>::iterator begin();
    std::vector<int>::iterator end();
    void addNumber(const int number);
    void addNumber(const int number, const unsigned int size);
    void addNumber(const std::vector<int>::const_iterator start, \
                   const std::vector<int>::const_iterator end);
    int shortestSpan() const;
    int longestSpan() const;
    unsigned int getSize() const;
};

#endif
