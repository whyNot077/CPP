#include "Fixed.hpp"

void print_a(const Fixed &fixed) {
    std::cout << "a is " << CYAN << fixed << DEFAULT << std::endl;
    std::cout << "I stored a to Fixed point value of " << MAGENTA << fixed.getRawBits() << DEFAULT << "\n" << std::endl;
}

void print_b(const Fixed &fixed) {
    std::cout << "b is " << CYAN << fixed << DEFAULT << std::endl;
    std::cout << "I stored b to Fixed point value of " << MAGENTA << fixed.getRawBits() << DEFAULT << "\n" << std::endl;
}

void print_max(const Fixed &a, const Fixed &b) {
    std::cout << "a is " << CYAN << a << DEFAULT << std::endl;
    std::cout << "b is " << CYAN << b << DEFAULT << std::endl;
    std::cout << "max is " << CYAN << Fixed::max(a, b) << DEFAULT << "\n" << std::endl;
}

int main() {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    print_a(a);

    std::cout << ++a << std::endl;
    print_a(a);

    std::cout << a << std::endl;
    print_a(a);

    std::cout << a++ << std::endl;
    print_a(a);

    std::cout << a << std::endl;
    print_a(a);

    std::cout << b << std::endl;
    print_b(b);

    std::cout << Fixed::max(a, b) << std::endl;
    print_max(a, b);

    return 0;
}
