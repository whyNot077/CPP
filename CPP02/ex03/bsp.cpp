#include "Point.hpp"

/*
• a, b, c: The vertices of our beloved triangle.
• point: The point to check.
• Returns: True if the point is inside the triangle. False otherwise.
Thus, if the point is a vertex or on edge, it will return False.
*/
bool bsp(const Point &a, const Point &b, const Point &c, const Point &point) {
    Point vector_B = b - a;
    Point vector_C = c - a;
    Point vector_P = point - a;

    Fixed dot_BB = vector_B * vector_B;
    Fixed dot_BC = vector_B * vector_C;
    Fixed dot_BP = vector_B * vector_P;
    Fixed dot_CC = vector_C * vector_C;
    Fixed dot_CP = vector_C * vector_P;

    Fixed denom = dot_BB * dot_CC - dot_BC * dot_BC;
    
    if (denom == 0) {
        return false;
    }

    Fixed u = (dot_CC * dot_BP - dot_BC * dot_CP) / denom;
    Fixed v = (dot_BB * dot_CP - dot_BC * dot_BP) / denom;
    Fixed w = Fixed(1) - u - v;

    return (u >= 0) && (v >= 0) && (w >= 0);
}



bool is_triangle(Point const &a, Point const &b, Point const &c) {
    Point vector_AB = b - a;
    Point vector_AC = c - a;

    Fixed x1 = vector_AB.getX();
    Fixed y1 = vector_AB.getY();
    Fixed x2 = vector_AC.getX();
    Fixed y2 = vector_AC.getY();

    Fixed cross_product = x1 * y2 - x2 * y1;
    return cross_product != 0;
}
