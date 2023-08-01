#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define DEFAULT "\033[0m"

class Point {
private:
    const Fixed m_x;
    const Fixed m_y;

public:
    Point();
    Point(const Point &point);
    Point(const Fixed x, const Fixed y);
    Point(const float x, const float y);
    ~Point();

    Point &operator=(const Point &point);
    Point operator-(const Point &point) const;
    Fixed operator*(const Point &point) const;

    const Fixed getX(void) const;
    const Fixed getY(void) const;
};

bool bsp( Point const &a, Point const &b, Point const &c, Point const &point);
bool is_triangle(Point const &a, Point const &b, Point const &c);

#endif
