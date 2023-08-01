#include "Fixed.hpp"
#include "Point.hpp"

void print_x(const Fixed &fixed) {
    std::cout << "x is " << CYAN << fixed << DEFAULT << std::endl;
}

void print_y(const Fixed &fixed) {
    std::cout << "y is " << CYAN << fixed << DEFAULT << std::endl;
}

void print_point(const Point &point) {
    print_x(point.getX());
    print_y(point.getY());
}

void print_is_triangle(Point const &a, Point const &b, Point const &c) {
    std::cout << "== A ==" << std::endl;
    print_point(a);
    std::cout << "== B ==" << std::endl;
    print_point(b);
    std::cout << "== C ==" << std::endl;
    print_point(c);
    std::cout << RED << "\nIs A, B, C make a triangle?" << DEFAULT << std::endl;
    if (is_triangle(a, b, c)) {
        std::cout << GREEN << "Yes" << DEFAULT << std::endl;
        return ;
    }
    std::cout << RED << "No" << DEFAULT << std::endl;
    exit(1);
}

void print_in_triangle(Point const &a, Point const &b, Point const &c, Point const &point) {
    std::cout << "== Point ==" << std::endl;
    print_point(point);
    if (bsp(a, b, c, point)) {
        std::cout << GREEN << "Yes" << DEFAULT << std::endl;
        return ;
    }
    std::cout << RED << "No" << DEFAULT << std::endl;
}

int main() {
    Point a(0, 0);
    Point b(0, 6);
    Point c(6, 0);

    print_is_triangle(a, b, c);

    Point p1(0, 0);
    print_in_triangle(a, b, c, p1);
    
    Point p2(1, 1);
    print_in_triangle(a, b, c, p2);
    
    Point p3(2, 2);
    print_in_triangle(a, b, c, p3);
    
    Point p4(3, 3);
    print_in_triangle(a, b, c, p4);
    
    Point p5(4, 4);
    print_in_triangle(a, b, c, p5);
    
    Point p6(5, 5);
    print_in_triangle(a, b, c, p6);
    
    Point p7(6, 6);
    print_in_triangle(a, b, c, p7);

    return 0;
}
