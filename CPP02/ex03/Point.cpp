#include "Point.hpp"

Point::Point() : m_x(0), m_y(0) { }

Point::Point(const Point &point) {
    *this = point;
}

Point::Point(const Fixed x, const Fixed y) : m_x(x), m_y(y) { }
Point::Point(const float x, const float y) : m_x(x), m_y(y) { }

Point::~Point() { }

Point &Point::operator=(const Point &point) {
    if (this != &point) {
        std::cout << YELLOW << "Const Fixed cannot be modified" << DEFAULT << std::endl;
    }
    return *this;
}

Point Point::operator-(const Point &point) const {
    return Point(m_x - point.m_x, m_y - point.m_y);
}

Fixed Point::operator*(const Point &point) const {
    return m_x * point.m_x + m_y * point.m_y;
}

const Fixed Point::getX(void) const {
    return m_x;
}

const Fixed Point::getY(void) const {
    return m_y;
}
