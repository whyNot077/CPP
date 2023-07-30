#include "Point.hpp"

Point::Point() : m_x(0), m_y(0) { }

Point::Point(const Point &point) {
    *this = point;
}

Point::Point(const float x, const float y) : m_x(x), m_y(y) { }

Point::~Point() { }

Point &Point::operator=(const Point &point) {
    if (this != &point) {
        Fixed x = point.getX();
        Fixed y = point.getY();
    }
    return *this;
}

const Fixed Point::getX(void) const {
    return m_x;
}

const Fixed Point::getY(void) const {
    return m_y;
}
